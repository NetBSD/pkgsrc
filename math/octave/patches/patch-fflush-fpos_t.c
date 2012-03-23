$NetBSD: patch-fflush-fpos_t.c,v 1.1 2012/03/23 22:32:59 christos Exp $

--- libgnu/fflush.c.orig	2011-08-03 23:59:51.000000000 -0400
+++ libgnu/fflush.c	2012-03-23 18:24:54.000000000 -0400
@@ -24,6 +24,7 @@
 #include <stdio.h>
 
 #include <errno.h>
+#include <string.h>
 #include <unistd.h>
 
 #include "freading.h"
@@ -97,17 +98,12 @@
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
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
 # endif
   fp_->_flags |= __SOFF;
 #endif
