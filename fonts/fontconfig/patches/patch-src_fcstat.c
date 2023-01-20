$NetBSD: patch-src_fcstat.c,v 1.6 2023/01/20 13:10:09 wiz Exp $

The argument types to scandir(3) differ between different OSes.
I used the provided alphasort instead of rewriting the equivalent
sorter function.  statvfs and fstatvfs need another include file,
at least on MirBSD.

--- src/fcstat.c.orig	2016-04-06 03:22:55.000000000 +0000
+++ src/fcstat.c
@@ -52,6 +52,12 @@ typedef long long INT64;
 #define EPOCH_OFFSET 11644473600i64
 typedef __int64 INT64;
 #endif
+#ifdef __MirBSD__
+#include <sys/statvfs.h>
+#endif
+#if defined(_SCO_DS)
+#include "../scandir.c"
+#endif
 
 /* Workaround for problems in the stat() in the Microsoft C library:
  *
@@ -159,7 +165,11 @@ Adler32Finish (struct Adler32 *ctx)
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
@@ -263,7 +273,11 @@ FcDirChecksum (const FcChar8 *dir, time_
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
 
