$NetBSD: patch-libguile_threads.c,v 1.1 2016/12/03 03:15:33 marino Exp $

DragonFly support.

--- libguile/threads.c.orig	2016-06-20 20:35:06 UTC
+++ libguile/threads.c
@@ -2252,7 +2252,7 @@ scm_ia64_ar_bsp (const void *opaque)
   return (void *) ctx->uc_mcontext.sc_ar_bsp;
 }
 # endif /* linux */
-# ifdef __FreeBSD__
+# if defined __FreeBSD__ || defined __DragonFly__
 #  include <ucontext.h>
 void *
 scm_ia64_register_backing_store_base (void)
