$NetBSD: patch-hald_linux_blockdev.c,v 1.1 2020/03/15 20:28:41 tnn Exp $

Add missing include.

--- hald/linux/blockdev.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/blockdev.c
@@ -35,6 +35,7 @@
 #include <dirent.h>
 #include <string.h>
 #include <sys/stat.h>
+#include <sys/sysmacros.h> /* for makedev(), major(), minor() */
 #include <syslog.h>
 #include <unistd.h>
 #include <errno.h>
