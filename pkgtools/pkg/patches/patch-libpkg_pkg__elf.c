$NetBSD: patch-libpkg_pkg__elf.c,v 1.1 2016/10/25 11:51:40 khorben Exp $

--- libpkg/pkg_elf.c.orig	2016-07-05 15:06:13.000000000 +0000
+++ libpkg/pkg_elf.c
@@ -787,6 +787,8 @@ pkg_get_myarch_elfparse(char *dest, size
 #if defined(__DragonFly__)
 	snprintf(dest, sz, "%s:%d.%d",
 	    osname, version / 100000, (((version / 100 % 1000)+1)/2)*2);
+#elif defined(__NetBSD__)
+	snprintf(dest, sz, "%s:%d", osname, (version + 1000000) / 100000000);
 #else
 	snprintf(dest, sz, "%s:%d", osname, version / 100000);
 #endif
