$NetBSD: patch-gcc_opts.cc,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/opts.cc.orig	2026-06-12 06:09:06.638526252 +0000
+++ gcc/opts.cc
@@ -3347,6 +3347,7 @@ common_handle_option (struct gcc_options
       break;

     case OPT_fuse_ld_bfd:
+    case OPT_fuse_ld_classic:
     case OPT_fuse_ld_gold:
     case OPT_fuse_ld_lld:
     case OPT_fuse_ld_mold:
