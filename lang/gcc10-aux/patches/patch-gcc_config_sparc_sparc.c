$NetBSD: patch-gcc_config_sparc_sparc.c,v 1.1 2022/03/13 08:34:04 nia Exp $

Invoke subtarget-specific code for replacing builtin functions.
Causes "cabsl" to be converted to _c99_cabsl on NetBSD.
https://gcc.gnu.org/pipermail/gcc-patches/2021-February/565290.html

--- gcc/config/sparc/sparc.c.orig	2020-07-23 06:35:17.480386051 +0000
+++ gcc/config/sparc/sparc.c
@@ -10993,6 +10993,9 @@ sparc_init_builtins (void)
 
   if (TARGET_VIS)
     sparc_vis_init_builtins ();
+#ifdef SUBTARGET_INIT_BUILTINS
+  SUBTARGET_INIT_BUILTINS;
+#endif
 }
 
 /* Create builtin functions for FPU instructions.  */
