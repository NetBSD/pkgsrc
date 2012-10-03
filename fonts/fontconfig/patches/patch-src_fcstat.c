$NetBSD: patch-src_fcstat.c,v 1.1.2.2 2012/10/03 14:24:35 tron Exp $

The argument types to scandir(3) differ between different OSes.
OpenBSD seems to be still different. I used the provided alphasort
instead of rewriting the equivalent sorter function.
statvfs and fstatvfs need another include file, at least on MirBSD.
--- src/fcstat.c.orig	Wed Sep 26 08:58:18 2012
+++ src/fcstat.c
@@ -42,6 +42,9 @@
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
 #endif
+#ifdef __MirBSD__
+#include <sys/statvfs.h>
+#endif
 
 #ifdef _WIN32
 
@@ -161,7 +164,11 @@ Adler32Finish (struct Adler32 *ctx)
 #ifdef HAVE_STRUCT_DIRENT_D_TYPE
 /* dirent.d_type can be relied upon on FAT filesystem */
 static FcBool
+# ifdef __MirBSD__
+FcDirChecksumScandirFilter(struct dirent *entry)
+# else
 FcDirChecksumScandirFilter(const struct dirent *entry)
+# endif
 {
     return entry->d_type != DT_DIR;
 }
@@ -191,7 +198,11 @@ FcDirChecksum (const FcChar8 *dir, time_
 #else
 		 NULL,
 #endif
+#ifdef __MirBSD__
+		 &alphasort);
+#else
 		 &FcDirChecksumScandirSorter);
+#endif
     if (n == -1)
 	return -1;
 
