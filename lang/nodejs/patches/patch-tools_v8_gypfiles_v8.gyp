$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.5 2025/05/07 05:56:48 adam Exp $

Add -larm on NetBSD ARM platforms.

--- tools/v8_gypfiles/v8.gyp.orig	2025-05-06 12:36:34.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -1308,6 +1308,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access.
+        # NetBSD/arm also needs -larm.
+        ['OS=="netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         # Clang needs it for some atomic operations (https://clang.llvm.org/docs/Toolchain.html#atomics-library).
         ['(OS=="linux" and clang==1) or (v8_current_cpu in ["mips64", "mips64el", "arm", "riscv64", "loong64"])', {
           'link_settings': {
