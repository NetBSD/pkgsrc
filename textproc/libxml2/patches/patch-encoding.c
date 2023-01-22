$NetBSD: patch-encoding.c,v 1.4 2023/01/22 10:30:09 wiz Exp $

Avoid potential undefined behaviour by casting arg to toupper()
to an appropriate value range.

Also, on NetBSD, add CP1141 encoding alias.

--- encoding.c.orig	2022-10-14 12:20:48.000000000 +0000
+++ encoding.c	2023-01-21 13:21:59.140034252 +0000
@@ -1047,7 +1047,7 @@
 	return(NULL);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1082,7 +1082,7 @@
 	return(-1);
 
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(alias[i]);
+        upper[i] = toupper((unsigned char)alias[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1184,7 +1184,7 @@
 	name = alias;
 
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1360,7 +1360,7 @@
 	return(NULL);
     }
     for (i = 0;i < 499;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
@@ -1465,6 +1465,9 @@
     xmlRegisterCharEncodingHandlersISO8859x ();
 #endif
 #endif
+#ifdef __NetBSD__ /* XXX needed by selftest */
+    xmlAddEncodingAlias("CP1141", "IBM-1141");
+#endif
 
 }
 
@@ -1706,7 +1709,7 @@
      * Check first for directly registered encoding names
      */
     for (i = 0;i < 99;i++) {
-        upper[i] = toupper(name[i]);
+        upper[i] = toupper((unsigned char)name[i]);
 	if (upper[i] == 0) break;
     }
     upper[i] = 0;
