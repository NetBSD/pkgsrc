$NetBSD: patch-src_fcstat.c,v 1.2 2013/03/14 19:32:33 drochner Exp $

The argument types to scandir(3) differ between different OSes.
OpenBSD seems to be still different. I used the provided alphasort
instead of rewriting the equivalent sorter function.
statvfs and fstatvfs need another include file, at least on MirBSD.
--- src/fcstat.c.orig	2013-01-08 06:42:23.000000000 +0000
+++ src/fcstat.c
@@ -42,6 +42,9 @@
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
 #endif
+#ifdef __MirBSD__
+#include <sys/statvfs.h>
+#endif
 
 #ifdef _WIN32
 #ifdef __GNUC__
@@ -158,7 +161,11 @@ Adler32Finish (struct Adler32 *ctx)
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
@@ -189,7 +196,11 @@ FcDirChecksum (const FcChar8 *dir, time_
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
 
