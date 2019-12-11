$NetBSD: patch-util_drm.c,v 1.1 2019/12/11 16:44:22 jperkin Exp $

Support SunOS.

--- util/drm.c.orig	2019-08-15 19:01:43.000000000 +0000
+++ util/drm.c
@@ -38,7 +38,13 @@ int qemu_drm_rendernode_open(const char
 
     fd = -1;
     while ((e = readdir(dir))) {
+#ifdef __sun
+	struct stat s;
+	stat(e->d_name, &s);
+	if (!(s.st_mode & S_IFCHR)) {
+#else
         if (e->d_type != DT_CHR) {
+#endif
             continue;
         }
 
