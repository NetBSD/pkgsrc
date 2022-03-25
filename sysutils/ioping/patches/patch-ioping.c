$NetBSD: patch-ioping.c,v 1.1 2022/03/25 11:39:06 wiz Exp $

Not every system has getopt_long_only().

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
