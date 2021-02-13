$NetBSD: patch-gcc_config_sparc_sparc.c,v 1.1 2021/02/13 15:56:16 maya Exp $

Invoke subtarget-specific code for replacing builtin functions.
Causes "cabsl" to be converted to _c99_cabsl on NetBSD.
https://gcc.gnu.org/pipermail/gcc-patches/2021-February/565290.html

--- gcc/config/sparc/sparc.c.orig	2018-04-06 22:33:55.000000000 +0000
+++ gcc/config/sparc/sparc.c
@@ -10208,6 +10208,9 @@ sparc_init_builtins (void)
 
   if (TARGET_VIS)
     sparc_vis_init_builtins ();
+#ifdef SUBTARGET_INIT_BUILTINS
+  SUBTARGET_INIT_BUILTINS;
+#endif
 }
 
 /* Create builtin functions for FPU instructions.  */
