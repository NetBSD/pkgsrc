$NetBSD: patch-gnulib-lib-fflush.c,v 1.2 2014/01/25 02:54:27 agc Exp $

fix for fpos_t/fgetpos/fsetpos from joerg

--- gnulib/lib/fflush.c	2014/01/25 02:18:50	1.1
+++ gnulib/lib/fflush.c	2014/01/25 02:19:22
@@ -96,7 +96,7 @@
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #  if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
