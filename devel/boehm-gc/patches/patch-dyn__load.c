$NetBSD: patch-dyn__load.c,v 1.4 2018/01/10 09:16:20 wiz Exp $

Support DragonFly.

--- dyn_load.c.orig	2017-12-23 08:46:29.000000000 +0000
+++ dyn_load.c
@@ -426,7 +426,7 @@ GC_INNER GC_bool GC_register_main_static
 # endif
 #endif /* __GLIBC__ >= 2 || PLATFORM_ANDROID */
 
-#if (defined(FREEBSD) && __FreeBSD__ >= 7)
+#if (defined(FREEBSD) && __FreeBSD__ >= 7) || defined __DragonFly__
   /* On the FreeBSD system, any target system at major version 7 shall   */
   /* have dl_iterate_phdr; therefore, we need not make it weak as below. */
 # ifndef HAVE_DL_ITERATE_PHDR
