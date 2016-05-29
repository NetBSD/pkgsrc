$NetBSD: patch-makepath.c,v 1.1.1.1 2016/05/29 22:24:33 abs Exp $

Do not depend on strdupa() - could make this conditional?

--- makepath.c.orig	2015-08-22 21:06:22.000000000 +0000
+++ makepath.c
@@ -33,9 +33,12 @@ int mkpath(char *dir, mode_t mode)
 	if (strlen(dir) == 1 && dir[0] == '/')
 		return 0;
 
-	mkpath(dirname(strdupa(dir)), mode);
+        char *buf = strdup(dir);
+	mkpath(dirname(buf), mode);
 
-	return mkdir(dir, mode);
+        int ret = mkdir(buf, mode);
+        free(buf);
+        return ret;
 }
 
 /**
