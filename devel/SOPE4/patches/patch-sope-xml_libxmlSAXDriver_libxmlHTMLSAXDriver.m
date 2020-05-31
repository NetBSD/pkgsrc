$NetBSD: patch-sope-xml_libxmlSAXDriver_libxmlHTMLSAXDriver.m,v 1.1 2020/05/31 14:36:21 rillig Exp $

On NetBSD-8.0-x86_64:

libxmlHTMLSAXDriver.m:784:9: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
libxmlHTMLSAXDriver.m:797:49: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]

https://github.com/inverse-inc/sope/pull/53

--- sope-xml/libxmlSAXDriver/libxmlHTMLSAXDriver.m.orig	2017-10-18 15:19:24.000000000 +0000
+++ sope-xml/libxmlSAXDriver/libxmlHTMLSAXDriver.m
@@ -781,12 +781,12 @@ static void error(void *udata, const cha
   SaxParseException *e;
   
   if (!reportInvalidTags && msg != NULL) {
-    if (toupper(msg[0]) == 'T') {
+    if (toupper((unsigned char) msg[0]) == 'T') {
       if (strncasecmp(tagInvalidMsg, msg, strlen(tagInvalidMsg)) == 0)
         return;
     }
 #if 0
-    else if (toupper(msg[0]) == 'U') {
+    else if (toupper((unsigned char) msg[0]) == 'U') {
       if (strncasecmp(unexpectedNobrCloseMsg, msg, 
                       strlen(unexpectedNobrCloseMsg)) == 0)
         return;
@@ -794,7 +794,7 @@ static void error(void *udata, const cha
     }
 #endif
   }
-  if (!reportUnclosedEntities && msg != NULL && toupper(msg[0]) == 'H') {
+  if (!reportUnclosedEntities && msg != NULL && toupper((unsigned char) msg[0]) == 'H') {
     if (strncasecmp(unclosedEntityInvalidMsg, msg, 
                     strlen(unclosedEntityInvalidMsg)) == 0)
       return;
