$NetBSD: patch-fflush-fpos_t.c,v 1.2 2016/02/16 04:21:40 dbj Exp $

--- libgnu/fflush.c.orig	2015-05-23 14:36:16.000000000 +0000
+++ libgnu/fflush.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 
 #include <errno.h>
+#include <string.h>
 #include <unistd.h>
 
 #include "freading.h"
@@ -103,17 +104,12 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
-  /* fp_->_offset is an fpos_t.  */
-  /* Use a union, since on NetBSD, the compilation flags determine
-     whether fpos_t is typedef'd to off_t or a struct containing a
-     single off_t member.  */
-  union
-    {
-      fpos_t f;
-      off_t o;
-    } u;
-  u.o = pos;
-  fp_->_offset = u.f;
+  /*
+   * fp_->_offset is an fpos_t or off_t
+   * in either case the off_t part is the first member of it.
+   */
+  memset(&fp_->_offset, 0, sizeof(fp_->_offset));
+  memcpy(&fp_->_offset, &pos, sizeof(pos));
 #   endif
   fp_->_flags |= __SOFF;
 #  endif
