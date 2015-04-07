$NetBSD: patch-lib_fseeko.c,v 1.1 2015/04/07 22:08:36 hiramatsu Exp $

Definition of FILE struct is changed on NetBSD 6.

--- lib/fseeko.c.orig	2015-04-05 22:42:44.000000000 +0900
+++ lib/fseeko.c	2015-04-05 22:42:52.000000000 +0900
@@ -125,7 +125,7 @@
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
