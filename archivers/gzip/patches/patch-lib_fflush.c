$NetBSD: patch-lib_fflush.c,v 1.1 2013/06/10 11:56:58 ryoon Exp $

--- lib/fflush.c.orig	2012-06-17 17:05:17.000000000 +0000
+++ lib/fflush.c
@@ -94,7 +94,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
