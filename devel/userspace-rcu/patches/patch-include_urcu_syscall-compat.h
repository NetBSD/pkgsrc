$NetBSD: patch-include_urcu_syscall-compat.h,v 1.2 2025/09/06 09:28:59 he Exp $

Treat NetBSD the same as FreeBSD and OpenBSD.

--- include/urcu/syscall-compat.h.orig	2020-06-27 02:29:41.649133194 +0200
+++ include/urcu/syscall-compat.h	2020-06-27 02:29:43.106570959 +0200
@@ -16,7 +16,7 @@
 
 #elif defined(__CYGWIN__) || defined(__APPLE__) || \
 	defined(__FreeBSD__) || defined(__DragonFly__) || \
-	defined(__OpenBSD__)
+	defined(__OpenBSD__) || defined(__NetBSD__)
 /* Don't include anything on these platforms. */
 
 #else
