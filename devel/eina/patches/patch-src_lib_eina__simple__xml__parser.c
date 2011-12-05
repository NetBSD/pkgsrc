$NetBSD: patch-src_lib_eina__simple__xml__parser.c,v 1.1 2011/12/05 17:14:52 joerg Exp $

--- src/lib/eina_simple_xml_parser.c.orig	2011-11-09 07:12:35.000000000 +0000
+++ src/lib/eina_simple_xml_parser.c
@@ -121,7 +121,7 @@ static inline const char *
 _eina_simple_xml_whitespace_find(const char *itr, const char *itr_end)
 {
    for (; itr < itr_end; itr++)
-     if (isspace(*itr)) break;
+     if (isspace((unsigned char)*itr)) break;
    return itr;
 }
 
@@ -129,7 +129,7 @@ static inline const char *
 _eina_simple_xml_whitespace_skip(const char *itr, const char *itr_end)
 {
    for (; itr < itr_end; itr++)
-     if (!isspace(*itr)) break;
+     if (!isspace((unsigned char)*itr)) break;
    return itr;
 }
 
@@ -137,7 +137,7 @@ static inline const char *
 _eina_simple_xml_whitespace_unskip(const char *itr, const char *itr_start)
 {
    for (itr--; itr > itr_start; itr--)
-     if (!isspace(*itr)) break;
+     if (!isspace((unsigned char)*itr)) break;
    return itr + 1;
 }
 
@@ -309,7 +309,7 @@ eina_simple_xml_parse(const char *buf, u
                            (!memcmp(itr + 2, "DOCTYPE",
                                     sizeof("DOCTYPE") - 1)) &&
                            ((itr[2 + sizeof("DOCTYPE") - 1] == '>') ||
-                            (isspace(itr[2 + sizeof("DOCTYPE") - 1]))))
+                            (isspace((unsigned char)itr[2 + sizeof("DOCTYPE") - 1]))))
                          {
                             type = EINA_SIMPLE_XML_DOCTYPE;
                             toff = sizeof("!DOCTYPE") - 1;
@@ -455,7 +455,7 @@ eina_simple_xml_tag_attributes_find(cons
 
    for (; itr < itr_end; itr++)
      {
-        if (!isspace(*itr))
+        if (!isspace((unsigned char)*itr))
           {
              /* user skip tagname and already gave it the attributes */
              if (*itr == '=')
@@ -492,7 +492,7 @@ eina_simple_xml_attributes_parse(const c
 
         key = p;
         for (key_end = key; key_end < itr_end; key_end++)
-          if ((*key_end == '=') || (isspace(*key_end))) break;
+          if ((*key_end == '=') || (isspace((unsigned char)*key_end))) break;
         if (key_end == itr_end) return EINA_FALSE;
         if (key_end == key) continue;
 
@@ -504,7 +504,7 @@ eina_simple_xml_attributes_parse(const c
              value++;
           }
         for (; value < itr_end; value++)
-          if (!isspace(*value)) break;
+          if (!isspace((unsigned char)*value)) break;
         if (value == itr_end) return EINA_FALSE;
 
         if ((*value == '"') || (*value == '\''))
