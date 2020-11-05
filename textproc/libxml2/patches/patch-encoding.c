$NetBSD: patch-encoding.c,v 1.3 2020/11/05 17:45:55 adam Exp $

Fix building with ICU 68.1.
Avoid potential undefined behaviour by casting arg to toupper()
to an appropriate value range.
https://bugzilla.gnome.org/show_bug.cgi?id=766838

Also, on NetBSD, add CP1141 encoding alias.

--- encoding.c.orig	2019-10-22 18:46:01.000000000 +0000
+++ encoding.c
@@ -48,6 +48,11 @@
 #include "buf.h"
 #include "enc.h"
 
+#if !defined(FALSE)
+# define FALSE (1 == 0)
+# define TRUE (! FALSE)
+#endif
+
 static xmlCharEncodingHandlerPtr xmlUTF16LEHandler = NULL;
 static xmlCharEncodingHandlerPtr xmlUTF16BEHandler = NULL;
 
@@ -1027,7 +1032,7 @@ xmlGetEncodingAlias(const char *alias) {
 	return(NULL);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1062,7 +1067,7 @@ xmlAddEncodingAlias(const char *name, co
 	return(-1);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1164,7 +1169,7 @@ xmlParseCharEncoding(const char* name)
 	name = alias;
 
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1340,7 +1345,7 @@ xmlNewCharEncodingHandler(const char *na
 	return(NULL);
     }
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1442,6 +1447,9 @@ xmlInitCharEncodingHandlers(void) {
     xmlRegisterCharEncodingHandlersISO8859x ();
 #endif
 #endif
+#ifdef __NetBSD__ /* XXX needed by selftest */
+    xmlAddEncodingAlias("CP1141", "IBM-1141");
+#endif
 
 }
 
@@ -1669,7 +1677,7 @@ xmlFindCharEncodingHandler(const char *n
      * Check first for directly registered encoding names
      */
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
