$NetBSD: patch-vgauth_lib_impersonateLinux.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- vgauth/lib/impersonateLinux.c.orig	2016-02-16 20:06:48.000000000 +0000
+++ vgauth/lib/impersonateLinux.c
@@ -29,7 +29,7 @@
 #define  _GNU_SOURCE
 #include <unistd.h>
 
-#if !defined(__FreeBSD__) && !defined(sun) && !defined(__APPLE__)
+#if !defined(__FreeBSD__) && !defined(sun) && !defined(__APPLE__) && !defined(__NetBSD__)
 #include <asm/param.h>
 #include <locale.h>
 #include <sys/stat.h>
