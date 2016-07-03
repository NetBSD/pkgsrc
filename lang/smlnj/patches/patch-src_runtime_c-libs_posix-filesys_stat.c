$NetBSD: patch-src_runtime_c-libs_posix-filesys_stat.c,v 1.1 2016/07/03 19:35:13 dholland Exp $

Be explicit about truncating times, and avoid compiler warning.

--- src/runtime/c-libs/posix-filesys/stat.c~	2000-06-01 18:34:03.000000000 +0000
+++ src/runtime/c-libs/posix-filesys/stat.c
@@ -3,6 +3,7 @@
  * COPYRIGHT (c) 1995 by AT&T Bell Laboratories.
  */
 
+#include <stdint.h>
 #include "ml-unixdep.h"
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -34,6 +35,7 @@
 PVT ml_val_t mkStatRep (ml_state_t *msp, struct stat *buf)
 {
     int		    ftype;
+    int32_t	    tmp;
     ml_val_t        mode, ino, dev, uid, gid, nlink, sr, atime, mtime, ctime;
 
 #if ((S_IFDIR != 0x4000) || (S_IFCHR != 0x2000) || (S_IFBLK != 0x6000) || (S_IFREG != 0x8000) || (S_IFIFO != 0x1000) || (S_IFLNK != 0xA000) || (S_IFSOCK != 0xC000))
@@ -59,9 +61,14 @@ PVT ml_val_t mkStatRep (ml_state_t *msp,
     WORD_ALLOC (msp, nlink, (Word_t)(buf->st_nlink));
     WORD_ALLOC (msp, uid, (Word_t)(buf->st_uid));
     WORD_ALLOC (msp, gid, (Word_t)(buf->st_gid));
-    INT32_ALLOC (msp, atime, buf->st_atime);
-    INT32_ALLOC (msp, mtime, buf->st_mtime);
-    INT32_ALLOC (msp, ctime, buf->st_ctime);
+
+    /* XXX y2038 */
+    tmp = buf->st_atime;
+    INT32_ALLOC (msp, atime, tmp);
+    tmp = buf->st_mtime;
+    INT32_ALLOC (msp, mtime, tmp);
+    tmp = buf->st_ctime;
+    INT32_ALLOC (msp, ctime, tmp);
 
   /* allocate the stat record */
     ML_AllocWrite(msp,  0, MAKE_DESC(11, DTAG_record));
