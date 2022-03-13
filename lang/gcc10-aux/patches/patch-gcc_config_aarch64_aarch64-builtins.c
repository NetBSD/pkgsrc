$NetBSD: patch-gcc_config_aarch64_aarch64-builtins.c,v 1.1 2022/03/13 08:34:04 nia Exp $

initialise subtarget builtins so cabs*() are renamed.
https://gcc.gnu.org/pipermail/gcc-patches/2021-February/565289.html

--- gcc/config/aarch64/aarch64-builtins.c.orig	2017-01-20 21:03:41.000000000 +0000
+++ gcc/config/aarch64/aarch64-builtins.c	2018-11-10 00:44:41.905576216 +0000
@@ -1303,6 +1303,10 @@ aarch64_general_init_builtins (void)
 
   if (TARGET_MEMTAG)
     aarch64_init_memtag_builtins ();
+
+#ifdef SUBTARGET_INIT_BUILTINS
+  SUBTARGET_INIT_BUILTINS;
+#endif
 }
 
 /* Implement TARGET_BUILTIN_DECL for the AARCH64_BUILTIN_GENERAL group.  */
