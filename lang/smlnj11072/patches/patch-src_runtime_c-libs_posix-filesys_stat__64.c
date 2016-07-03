$NetBSD: patch-src_runtime_c-libs_posix-filesys_stat__64.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Be explicit about truncating times, and avoid compiler warning.

--- src/runtime/c-libs/posix-filesys/stat_64.c.orig	2004-11-24 20:27:30.000000000 +0000
+++ src/runtime/c-libs/posix-filesys/stat_64.c
@@ -4,6 +4,8 @@
  *
  * Copyright (c) 2004 by The Fellowship of SML/NJ
  */
+
+#include <stdint.h>
 #include "ml-unixdep.h"
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -36,6 +38,7 @@
 PVT ml_val_t mkStatRep (ml_state_t *msp, struct stat *buf)
 {
     int		    ftype;
+    int32_t	    tmp;
     ml_val_t        mode, ino, dev, uid, gid, nlink, sr, atime, mtime, ctime,
                     szhi, szlo;
 
@@ -68,9 +71,14 @@ PVT ml_val_t mkStatRep (ml_state_t *msp,
       WORD_ALLOC (msp, szhi, (Word_t)0);
     }
     WORD_ALLOC (msp, szlo, (Word_t)(buf->st_size));
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
     ML_AllocWrite(msp,  0, MAKE_DESC(12, DTAG_record));
