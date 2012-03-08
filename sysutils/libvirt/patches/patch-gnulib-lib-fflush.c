$NetBSD: patch-gnulib-lib-fflush.c,v 1.1 2012/03/08 01:12:52 joerg Exp $

--- gnulib/lib/fflush.c.orig	2011-05-17 06:12:57.000000000 +0000
+++ gnulib/lib/fflush.c
@@ -93,7 +93,7 @@ static inline void
 update_fpos_cache (FILE *fp, off_t pos)
 {
 #if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
