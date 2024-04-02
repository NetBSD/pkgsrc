$NetBSD: patch-common_compat.c,v 1.5 2024/04/02 02:13:01 charlotte Exp $

- Hide getauxval() symbol because the implementation is incomplete
  and breaks for example openssl on NetBSD/evbarm
  https://github.com/p11-glue/p11-kit/issues/192

- issetugid() et al. are hidden behind __BSD_VISIBLE on DragonFly, too.

--- common/compat.c.orig	2023-10-26 02:56:44.000000000 -0700
+++ common/compat.c	2024-04-01 19:04:55.358513000 -0700
@@ -49,7 +49,7 @@
  * This is needed to expose issetugid, getresuid, and getresgid, which are
  * hidden with the _XOPEN_SOURCE setting above
  */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #undef __BSD_VISIBLE
 #define __BSD_VISIBLE 1
 #endif
@@ -859,6 +859,9 @@
 #ifndef HAVE_GETAUXVAL
 
 unsigned long
+#if defined(__GNUC__) || defined(__clang__)
+__attribute__((visibility("hidden")))
+#endif
 getauxval (unsigned long type)
 {
 	static unsigned long secure = 0UL;
