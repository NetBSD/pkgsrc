$NetBSD: patch-fseeko-fpos_t.c,v 1.2 2016/02/16 04:21:40 dbj Exp $

--- libgnu/fseeko.c.orig	2015-05-23 14:36:16.000000000 +0000
+++ libgnu/fseeko.c
@@ -22,6 +22,9 @@
 /* Get off_t, lseek, _POSIX_VERSION.  */
 #include <unistd.h>
 
+/* mem* */
+#include <string.h>
+
 #include "stdio-impl.h"
 
 int
@@ -132,19 +135,12 @@ fseeko (FILE *fp, off_t offset, int when
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
-      /* fp_->_offset is an fpos_t.  */
-      {
-        /* Use a union, since on NetBSD, the compilation flags
-           determine whether fpos_t is typedef'd to off_t or a struct
-           containing a single off_t member.  */
-        union
-          {
-            fpos_t f;
-            off_t o;
-          } u;
-        u.o = pos;
-        fp_->_offset = u.f;
-      }
+      /*
+       * fp_->_offset is an fpos_t or off_t
+       * in either case the off_t part is the first member of it.
+       */
+      memset(&fp_->_offset, 0, sizeof(fp_->_offset));
+      memcpy(&fp_->_offset, &pos, sizeof(pos));
 # endif
       fp_->_flags |= __SOFF;
       fp_->_flags &= ~__SEOF;
