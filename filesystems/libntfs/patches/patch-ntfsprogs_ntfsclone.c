$NetBSD: patch-ntfsprogs_ntfsclone.c,v 1.1 2014/05/19 12:22:06 adam Exp $

--- ntfsprogs/ntfsclone.c.orig	2014-02-15 14:07:52.000000000 +0000
+++ ntfsprogs/ntfsclone.c
@@ -68,6 +68,19 @@
  */
 #define NTFS_DO_NOT_CHECK_ENDIANS
 
+#ifdef __NetBSD__
+#  include <sys/param.h>
+   /* NetBSD versions later than 2.99.9 have statvfs(2) instead of statfs(2) */
+#  if __NetBSD_Version__ >= 299000900
+#    include <sys/statvfs.h>
+#    define F_TYPE	f_fsid
+#  else
+#    define F_TYPE	f_type
+#  endif
+#else
+#  define F_TYPE	f_type
+#endif
+
 #include "debug.h"
 #include "types.h"
 #include "support.h"
@@ -161,8 +174,12 @@ static struct {
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
@@ -818,7 +835,7 @@ static void copy_cluster(int rescue, u64
 #ifndef NO_STATFS
 		int err = errno;
 		perr_printf("Write failed");
-		if (err == EIO && opt.stfs.f_type == 0x517b)
+		if (err == EIO && opt.stfs.F_TYPE == 0x517b)
 			Printf("Apparently you tried to clone to a remote "
 			       "Windows computer but they don't\nhave "
 			       "efficient sparse file handling by default. "
@@ -2238,7 +2255,7 @@ static void set_filesize(s64 filesize)
 		Printf("WARNING: Couldn't get filesystem type: "
 		       "%s\n", strerror(errno));
 	else
-		fs_type = opt.stfs.f_type;
+		fs_type = opt.stfs.F_TYPE;
 
 	if (fs_type == 0x52654973)
 		Printf("WARNING: You're using ReiserFS, it has very poor "
