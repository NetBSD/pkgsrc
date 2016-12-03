$NetBSD: patch-dyn__load.c,v 1.3 2016/12/03 03:09:26 marino Exp $

Support DragonFly.

--- dyn_load.c.orig	2016-08-02 19:36:14 UTC
+++ dyn_load.c
@@ -435,7 +435,7 @@ GC_INNER GC_bool GC_register_main_static
 # pragma weak dl_iterate_phdr
 #endif
 
-#if (defined(FREEBSD) && __FreeBSD__ >= 7)
+#if (defined(FREEBSD) && __FreeBSD__ >= 7) || defined __DragonFly__
   /* On the FreeBSD system, any target system at major version 7 shall   */
   /* have dl_iterate_phdr; therefore, we need not make it weak as above. */
 # define HAVE_DL_ITERATE_PHDR
