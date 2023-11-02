$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.1 2023/11/02 13:16:54 adam Exp $

Add -larm on NetBSD ARM platforms.

--- tools/v8_gypfiles/v8.gyp.orig	2022-11-04 14:54:27.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -975,6 +975,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
+        # NetBSD/arm also needs -larm.
+        ['OS == "netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         ['v8_current_cpu in ["mips64", "mips64el", "ppc", "arm", "riscv64", "loong64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
