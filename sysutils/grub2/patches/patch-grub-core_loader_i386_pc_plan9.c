$NetBSD: patch-grub-core_loader_i386_pc_plan9.c,v 1.1 2012/07/29 21:44:13 gsutre Exp $

Prevent warning with lang/gcc44, leading to build failure.

--- grub-core/loader/i386/pc/plan9.c.orig	2012-03-04 00:00:08.000000000 +0000
+++ grub-core/loader/i386/pc/plan9.c
@@ -102,6 +102,8 @@ grub_plan9_unload (void)
   return GRUB_ERR_NONE;
 }
 
+#pragma GCC diagnostic ignored "-Wstrict-aliasing"
+
 static grub_err_t
 grub_cmd_plan9 (grub_extcmd_context_t ctxt, int argc, char *argv[])
 {
