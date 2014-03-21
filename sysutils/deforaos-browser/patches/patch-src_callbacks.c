$NetBSD: patch-src_callbacks.c,v 1.1 2014/03/21 14:19:31 jperkin Exp $

Support unmount() on SunOS.

--- src/callbacks.c.orig	2013-03-11 01:38:09.000000000 +0000
+++ src/callbacks.c
@@ -18,7 +18,7 @@
 #include <sys/param.h>
 #ifndef __GNU__ /* XXX hurd portability */
 # include <sys/mount.h>
-# if defined(__linux__) || defined(__CYGWIN__)
+# if defined(__linux__) || defined(__CYGWIN__) || defined(__sun)
 #  define unmount(a, b) umount(a)
 # endif
 # ifndef unmount
