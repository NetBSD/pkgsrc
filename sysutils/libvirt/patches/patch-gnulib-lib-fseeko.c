$NetBSD: patch-gnulib-lib-fseeko.c,v 1.2 2014/01/25 02:54:27 agc Exp $

Fix for fpos_t from joerg

--- gnulib/lib/fseeko.c	2014/01/25 02:09:09	1.1
+++ gnulib/lib/fseeko.c	2014/01/25 02:17:10
@@ -125,7 +125,7 @@
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
