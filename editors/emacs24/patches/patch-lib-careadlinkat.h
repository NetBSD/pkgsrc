$NetBSD: patch-lib-careadlinkat.h,v 1.1 2012/11/26 16:56:16 martin Exp $

# the *at functions are only available for newer POSIX versions

--- lib/careadlinkat.h.orig	2012-08-23 07:33:42.000000000 +0200
+++ lib/careadlinkat.h	2012-11-26 17:22:41.000000000 +0100
@@ -20,6 +20,7 @@
 #ifndef _GL_CAREADLINKAT_H
 #define _GL_CAREADLINKAT_H
 
+#define _POSIX_C_SOURCE	200809L
 #include <fcntl.h>
 #include <unistd.h>
 
