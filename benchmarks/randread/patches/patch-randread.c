$NetBSD: patch-randread.c,v 1.1 2015/01/01 09:22:23 dholland Exp $

This does not actually use either disklabel.h or ioctl.h, so improve
portability by not including them.

--- randread.c~	2002-09-11 06:25:46.000000000 +0000
+++ randread.c
@@ -9,8 +9,6 @@ char VERSION[] = "@(#) randread v0.2 200
 
 #include <sys/types.h>
 
-#include <sys/disklabel.h>
-#include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <errno.h>
