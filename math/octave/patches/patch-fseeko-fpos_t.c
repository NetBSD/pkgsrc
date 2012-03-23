$NetBSD: patch-fseeko-fpos_t.c,v 1.1 2012/03/23 22:32:59 christos Exp $

--- libgnu/fseeko.c.orig	2011-08-09 22:10:48.000000000 -0400
+++ libgnu/fseeko.c	2012-03-23 18:24:47.000000000 -0400
@@ -25,6 +25,9 @@
 /* Get off_t and lseek.  */
 #include <unistd.h>
 
+/* mem* */
+#include <string.h>
+
 #include "stdio-impl.h"
 
 int
@@ -115,19 +118,12 @@
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
