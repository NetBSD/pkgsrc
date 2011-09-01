$NetBSD: patch-parser.c,v 1.2 2011/09/01 14:42:09 obache Exp $

* fixes CVE-2009-2414 and CVE-2009-2416.

--- parser.c.orig	2001-09-14 14:09:41.000000000 +0000
+++ parser.c
@@ -5164,11 +5164,15 @@ xmlParseNotationType(xmlParserCtxtPtr ct
 		                 "Name expected in NOTATION declaration\n");
 	    ctxt->wellFormed = 0;
 	    ctxt->disableSAX = 1;
-	    return(ret);
+	    xmlFreeEnumeration(ret);
+	    return(NULL);
 	}
 	cur = xmlCreateEnumeration(name);
 	xmlFree(name);
-	if (cur == NULL) return(ret);
+	if (cur == NULL) {
+	    xmlFreeEnumeration(ret);
+	    return(NULL);
+	}
 	if (last == NULL) ret = last = cur;
 	else {
 	    last->next = cur;
@@ -5183,9 +5187,8 @@ xmlParseNotationType(xmlParserCtxtPtr ct
 	                     "')' required to finish NOTATION declaration\n");
 	ctxt->wellFormed = 0;
 	ctxt->disableSAX = 1;
-	if ((last != NULL) && (last != ret))
-	    xmlFreeEnumeration(last);
-	return(ret);
+	xmlFreeEnumeration(ret);
+	return(NULL);
     }
     NEXT;
     return(ret);
@@ -5236,7 +5239,10 @@ xmlParseEnumerationType(xmlParserCtxtPtr
 	}
 	cur = xmlCreateEnumeration(name);
 	xmlFree(name);
-	if (cur == NULL) return(ret);
+	if (cur == NULL) {
+	    xmlFreeEnumeration(ret);
+	    return(NULL);
+	}
 	if (last == NULL) ret = last = cur;
 	else {
 	    last->next = cur;
@@ -5715,13 +5721,22 @@ xmlParseElementChildrenContentDecl
     xmlChar *elem;
     xmlChar type = 0;
 
+    if (ctxt->depth > 128) {
+	ctxt->sax->error(ctxt->userData,
+		"xmlParseElementChildrenContentDecl : depth %d too deep\n",
+		ctxt->depth);
+	return(NULL);
+    }
+
     SKIP_BLANKS;
     GROW;
     if (RAW == '(') {
         /* Recurse on first child */
 	NEXT;
 	SKIP_BLANKS;
+	ctxt->depth++;
         cur = ret = xmlParseElementChildrenContentDecl(ctxt);
+	ctxt->depth--;
 	SKIP_BLANKS;
 	GROW;
     } else {
@@ -5865,7 +5880,9 @@ xmlParseElementChildrenContentDecl
 	    /* Recurse on second child */
 	    NEXT;
 	    SKIP_BLANKS;
+	    ctxt->depth++;
 	    last = xmlParseElementChildrenContentDecl(ctxt);
+	    ctxt->depth--;
 	    SKIP_BLANKS;
 	} else {
 	    elem = xmlParseNameComplex(ctxt);
