$NetBSD: patch-ntfsprogs_ntfsclone.c,v 1.2 2023/09/08 10:23:07 vins Exp $

Fix for NetBSD's statvfs(2).

--- ntfsprogs/ntfsclone.c.orig	2021-09-13 07:34:39.000000000 +0000
+++ ntfsprogs/ntfsclone.c
@@ -71,6 +71,19 @@
  */
 #define NTFS_DO_NOT_CHECK_ENDIANS
 
+#ifdef __NetBSD__
+#  include <sys/param.h>
+   /* NetBSD versions later than 2.99.9 have statvfs(2) instead of statfs(2) */
+#  if __NetBSD_Version__ >= 299000900
+#    include <sys/statvfs.h>
+#    define F_TYPE     f_fsid
+#  else
+#    define F_TYPE     f_type
+#  endif
+#else
+#  define F_TYPE       f_type
+#endif
+
 #include "param.h"
 #include "debug.h"
 #include "types.h"
@@ -166,8 +179,12 @@ static struct {
 	char *output;
 	char *volume;
 #ifndef NO_STATFS
+#if defined(__NetBSD__) && (__NetBSD_Version__ >= 299000900)
+	struct statvfs stfs;
+#else
 	struct statfs stfs;
 #endif
+#endif
 } opt;
 
 struct bitmap {
@@ -852,7 +869,7 @@ static void copy_cluster(int rescue, u64
 #ifndef NO_STATFS
 		int err = errno;
 		perr_printf("Write failed");
-		if (err == EIO && opt.stfs.f_type == 0x517b)
+		if (err == EIO && opt.stfs.F_TYPE == 0x517b)
 			Printf("Apparently you tried to clone to a remote "
 			       "Windows computer but they don't\nhave "
 			       "efficient sparse file handling by default. "
@@ -2312,7 +2329,7 @@ static void set_filesize(s64 filesize)
 		Printf("WARNING: Couldn't get filesystem type: "
 		       "%s\n", strerror(errno));
 	else
-		fs_type = opt.stfs.f_type;
+		fs_type = opt.stfs.F_TYPE;
 
 	if (fs_type == 0x52654973)
 		Printf("WARNING: You're using ReiserFS, it has very poor "
