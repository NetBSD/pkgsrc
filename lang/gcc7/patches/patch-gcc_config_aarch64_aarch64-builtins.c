$NetBSD: patch-gcc_config_aarch64_aarch64-builtins.c,v 1.1 2018/11/10 04:24:00 mrg Exp $

initialise subtarget builtins so cabs*() are renamed.

--- gcc/config/aarch64/aarch64-builtins.c.orig	2017-01-20 21:03:41.000000000 +0000
+++ gcc/config/aarch64/aarch64-builtins.c	2018-11-10 00:44:41.905576216 +0000
@@ -991,6 +991,9 @@
      register them.  */
   if (!TARGET_ILP32)
     aarch64_init_pauth_hint_builtins ();
+#ifdef SUBTARGET_INIT_BUILTINS
+  SUBTARGET_INIT_BUILTINS;
+#endif
 }
 
 tree
