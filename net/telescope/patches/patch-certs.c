$NetBSD: patch-certs.c,v 1.1 2025/07/26 21:41:39 vins Exp $

struct dirent misses a d_type member on SunOS. 

--- certs.c.orig	2024-12-30 09:09:39.000000000 +0000
+++ certs.c
@@ -207,8 +207,15 @@ certs_init(const char *certfile)
 		return (-1);
 
 	while ((dp = readdir(certdir)) != NULL) {
+#ifndef DT_REG
+		struct stat s;
+		stat(dp->d_name, &s);
+		if (S_ISREG(s.st_mode))
+			continue;
+#else
 		if (dp->d_type != DT_REG)
 			continue;
+#endif
 		if (push_identity(dp->d_name) == -1) {
 			closedir(certdir);
 			return (-1);
