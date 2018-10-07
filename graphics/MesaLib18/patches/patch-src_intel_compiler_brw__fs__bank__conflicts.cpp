$NetBSD: patch-src_intel_compiler_brw__fs__bank__conflicts.cpp,v 1.1 2018/10/07 23:49:31 ryoon Exp $

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415
FreeBSD Bugzilla: Bug 225415 graphics/mesa-dri: update to 18.0.0

compiler/brw_fs_bank_conflicts.cpp:719:25: error: scalar initializer cannot be empty
      vector_type s_p = {}, s_n = {};
                        ^~
compiler/brw_fs_bank_conflicts.cpp:719:35: error: scalar initializer cannot be empty
      vector_type s_p = {}, s_n = {};
                                  ^~

--- src/intel/compiler/brw_fs_bank_conflicts.cpp.orig	2018-02-09 02:17:59.000000000 +0000
+++ src/intel/compiler/brw_fs_bank_conflicts.cpp
@@ -716,7 +716,7 @@ namespace {
                    const weight_vector_type &conflicts)
    {
       const unsigned m = DIV_ROUND_UP(conflicts.size, vector_width);
-      vector_type s_p = {}, s_n = {};
+      vector_type s_p = {0}, s_n = {0};
 
       for (unsigned r = 0; r < m; r++) {
          s_p = adds(s_p, mask(bank_mask_p.v[r], conflicts.v[r]));
