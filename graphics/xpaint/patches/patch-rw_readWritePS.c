$NetBSD: patch-rw_readWritePS.c,v 1.1 2012/10/24 15:38:43 joerg Exp $

--- rw/readWritePS.c.orig	2012-10-24 12:51:26.000000000 +0000
+++ rw/readWritePS.c
@@ -383,7 +383,7 @@ ReadPS(char *file)
     fclose(fp);
 
     type_doc = TestPS(file);
-    if (!type_doc) return; /* should not happen anyway ... */
+    if (!type_doc) return NULL; /* should not happen anyway ... */
 
     strncpy(rad, file, 256),
     rad[256] = '\0';
