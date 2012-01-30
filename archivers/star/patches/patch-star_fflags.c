$NetBSD: patch-star_fflags.c,v 1.1 2012/01/30 03:43:58 sbd Exp $

<linux/fs.h> must be included before <linux/ext2_fs.h>

--- star/fflags.c.orig	2002-01-27 22:48:12.000000000 +0000
+++ star/fflags.c
@@ -41,6 +41,7 @@ static	char sccsid[] =
 #include "starsubs.h"
 #ifdef	__linux__
 #include <fctldefs.h>
+#include <linux/fs.h>
 #include <linux/ext2_fs.h>
 #include <sys/ioctl.h>
 #endif
