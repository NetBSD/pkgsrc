$NetBSD: patch-include_urcu_syscall-compat.h,v 1.1 2020/07/01 00:40:48 manu Exp $
--- include/urcu/syscall-compat.h.orig	2020-06-27 02:29:41.649133194 +0200
+++ include/urcu/syscall-compat.h	2020-06-27 02:29:43.106570959 +0200
@@ -32,9 +32,10 @@
 #elif defined(__linux__) || defined(__GLIBC__)
 #include <syscall.h>
 
 #elif defined(__CYGWIN__) || defined(__APPLE__) || \
-	defined(__FreeBSD__) || defined(__DragonFly__)
+	defined(__FreeBSD__) || defined(__DragonFly__) || \
+	defined(__NetBSD__)
 /* Don't include anything on these platforms. */
 
 #else
 #error "Add platform support to urcu/syscall-compat.h"
