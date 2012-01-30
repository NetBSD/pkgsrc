$NetBSD: patch-star_star__unix.c,v 1.1 2012/01/30 03:43:58 sbd Exp $

<linux/fs.h> must be included before <linux/ext2_fs.h>

--- star/star_unix.c.orig	2002-08-15 23:22:32.000000000 +0000
+++ star/star_unix.c
@@ -44,6 +44,7 @@ static	char sccsid[] =
 #include "xutimes.h"
 #ifdef	__linux__
 #include <fctldefs.h>
+#include <linux/fs.h>
 #include <linux/ext2_fs.h>
 #include <sys/ioctl.h>
 #endif
