$NetBSD$

Avoid potential undefined behaviour by casting arg to toupper()
to an appropriate value range.
https://bugzilla.gnome.org/show_bug.cgi?id=766838

Also, on NetBSD, add CP1141 encoding alias.

--- encoding.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ encoding.c
@@ -1018,7 +1018,7 @@ xmlGetEncodingAlias(const char *alias) {
 	return(NULL);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1053,7 +1053,7 @@ xmlAddEncodingAlias(const char *name, co
 	return(-1);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1155,7 +1155,7 @@ xmlParseCharEncoding(const char* name)
 	name = alias;
 
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1331,7 +1331,7 @@ xmlNewCharEncodingHandler(const char *na
 	return(NULL);
     }
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1433,6 +1433,9 @@ xmlInitCharEncodingHandlers(void) {
     xmlRegisterCharEncodingHandlersISO8859x ();
 #endif
 #endif
+#ifdef __NetBSD__ /* XXX needed by selftest */
+    xmlAddEncodingAlias("CP1141", "IBM-1141");
+#endif
 
 }
 
@@ -1660,7 +1663,7 @@ xmlFindCharEncodingHandler(const char *n
      * Check first for directly registered encoding names
      */
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
