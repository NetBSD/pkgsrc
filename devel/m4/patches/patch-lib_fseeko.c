$NetBSD: patch-lib_fseeko.c,v 1.1 2018/10/28 20:53:44 sevan Exp $

Treat Minix 3 same as NetBSD

--- lib/fseeko.c.orig	2018-10-28 20:33:23.728090000 +0000
+++ lib/fseeko.c
@@ -128,7 +128,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ || defined __ANDROID__
       /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Android */
-# if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000)
+# if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000) || defined __Minix__
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
