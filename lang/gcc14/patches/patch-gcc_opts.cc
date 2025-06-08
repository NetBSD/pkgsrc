$NetBSD: patch-gcc_opts.cc,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/opts.cc.orig	2025-05-23 11:02:04.840206164 +0000
+++ gcc/opts.cc
@@ -3289,6 +3289,7 @@ common_handle_option (struct gcc_options
       break;
 
     case OPT_fuse_ld_bfd:
+    case OPT_fuse_ld_classic:
     case OPT_fuse_ld_gold:
     case OPT_fuse_ld_lld:
     case OPT_fuse_ld_mold:
