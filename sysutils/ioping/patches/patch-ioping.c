$NetBSD: patch-ioping.c,v 1.2 2022/03/26 13:06:58 wiz Exp $

Not every system has getopt_long_only().

Claim NetBSD is like FreeBSD.

--- ioping.c.orig	2020-02-02 13:37:55.000000000 +0000
+++ ioping.c
@@ -45,8 +45,6 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 
-#define HAVE_GETOPT_LONG_ONLY
-
 #ifdef __linux__
 # include <sys/ioctl.h>
 # include <sys/mount.h>
@@ -71,7 +69,7 @@
 # define HAVE_STATVFS
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 # include <sys/ioctl.h>
 # include <sys/mount.h>
 # include <sys/disk.h>
