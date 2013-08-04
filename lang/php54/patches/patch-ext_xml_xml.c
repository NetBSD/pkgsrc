$NetBSD: patch-ext_xml_xml.c,v 1.1.2.2 2013/08/04 20:24:10 spz Exp $

Fix for CVE-2013-4113 as php 5.3.27.

--- ext/xml/xml.c.orig	2013-07-03 06:10:53.000000000 +0000
+++ ext/xml/xml.c
@@ -428,7 +428,7 @@ static void xml_parser_dtor(zend_rsrc_li
 	}
 	if (parser->ltags) {
 		int inx;
-		for (inx = 0; inx < parser->level; inx++)
+		for (inx = 0; ((inx < parser->level) && (inx < XML_MAXLEVEL)); inx++)
 			efree(parser->ltags[ inx ]);
 		efree(parser->ltags);
 	}
@@ -805,45 +805,50 @@ void _xml_startElementHandler(void *user
 		} 
 
 		if (parser->data) {
-			zval *tag, *atr;
-			int atcnt = 0;
+			if (parser->level <= XML_MAXLEVEL)  {
+				zval *tag, *atr;
+				int atcnt = 0;
 
-			MAKE_STD_ZVAL(tag);
-			MAKE_STD_ZVAL(atr);
+				MAKE_STD_ZVAL(tag);
+				MAKE_STD_ZVAL(atr);
 
-			array_init(tag);
-			array_init(atr);
+				array_init(tag);
+				array_init(atr);
 
-			_xml_add_to_info(parser,((char *) tag_name) + parser->toffset);
+				_xml_add_to_info(parser,((char *) tag_name) + parser->toffset);
 
-			add_assoc_string(tag,"tag",((char *) tag_name) + parser->toffset,1); /* cast to avoid gcc-warning */
-			add_assoc_string(tag,"type","open",1);
-			add_assoc_long(tag,"level",parser->level);
+				add_assoc_string(tag,"tag",((char *) tag_name) + parser->toffset,1); /* cast to avoid gcc-warning */
+				add_assoc_string(tag,"type","open",1);
+				add_assoc_long(tag,"level",parser->level);
 
-			parser->ltags[parser->level-1] = estrdup(tag_name);
-			parser->lastwasopen = 1;
+				parser->ltags[parser->level-1] = estrdup(tag_name);
+				parser->lastwasopen = 1;
 
-			attributes = (const XML_Char **) attrs;
+				attributes = (const XML_Char **) attrs;
 
-			while (attributes && *attributes) {
-				att = _xml_decode_tag(parser, attributes[0]);
-				val = xml_utf8_decode(attributes[1], strlen(attributes[1]), &val_len, parser->target_encoding);
-				
-				add_assoc_stringl(atr,att,val,val_len,0);
+				while (attributes && *attributes) {
+					att = _xml_decode_tag(parser, attributes[0]);
+					val = xml_utf8_decode(attributes[1], strlen(attributes[1]), &val_len, parser->target_encoding);
 
-				atcnt++;
-				attributes += 2;
+					add_assoc_stringl(atr,att,val,val_len,0);
 
-				efree(att);
-			}
+					atcnt++;
+					attributes += 2;
 
-			if (atcnt) {
-				zend_hash_add(Z_ARRVAL_P(tag),"attributes",sizeof("attributes"),&atr,sizeof(zval*),NULL);
-			} else {
-				zval_ptr_dtor(&atr);
-			}
+					efree(att);
+				}
+
+				if (atcnt) {
+					zend_hash_add(Z_ARRVAL_P(tag),"attributes",sizeof("attributes"),&atr,sizeof(zval*),NULL);
+				} else {
+					zval_ptr_dtor(&atr);
+				}
 
-			zend_hash_next_index_insert(Z_ARRVAL_P(parser->data),&tag,sizeof(zval*),(void *) &parser->ctag);
+				zend_hash_next_index_insert(Z_ARRVAL_P(parser->data),&tag,sizeof(zval*),(void *) &parser->ctag);
+			} else if (parser->level == (XML_MAXLEVEL + 1)) {
+				TSRMLS_FETCH();
+				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Maximum depth exceeded - Results truncated");
+			}
 		}
 
 		efree(tag_name);
@@ -895,7 +900,7 @@ void _xml_endElementHandler(void *userDa
 
 		efree(tag_name);
 
-		if (parser->ltags) {
+		if ((parser->ltags) && (parser->level <= XML_MAXLEVEL)) {
 			efree(parser->ltags[parser->level-1]);
 		}
 
@@ -979,18 +984,23 @@ void _xml_characterDataHandler(void *use
 						}
 					}
 
-					MAKE_STD_ZVAL(tag);
-					
-					array_init(tag);
-					
-					_xml_add_to_info(parser,parser->ltags[parser->level-1] + parser->toffset);
+					if (parser->level <= XML_MAXLEVEL) {
+						MAKE_STD_ZVAL(tag);
 
-					add_assoc_string(tag,"tag",parser->ltags[parser->level-1] + parser->toffset,1);
-					add_assoc_string(tag,"value",decoded_value,0);
-					add_assoc_string(tag,"type","cdata",1);
-					add_assoc_long(tag,"level",parser->level);
+						array_init(tag);
 
-					zend_hash_next_index_insert(Z_ARRVAL_P(parser->data),&tag,sizeof(zval*),NULL);
+						_xml_add_to_info(parser,parser->ltags[parser->level-1] + parser->toffset);
+
+						add_assoc_string(tag,"tag",parser->ltags[parser->level-1] + parser->toffset,1);
+						add_assoc_string(tag,"value",decoded_value,0);
+						add_assoc_string(tag,"type","cdata",1);
+						add_assoc_long(tag,"level",parser->level);
+
+						zend_hash_next_index_insert(Z_ARRVAL_P(parser->data),&tag,sizeof(zval*),NULL);
+					} else if (parser->level == (XML_MAXLEVEL + 1)) {
+						TSRMLS_FETCH();
+						php_error_docref(NULL TSRMLS_CC, E_WARNING, "Maximum depth exceeded - Results truncated");
+					}
 				}
 			} else {
 				efree(decoded_value);
