$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.2 2022/03/30 06:52:33 adam Exp $

Add -larm on netbsd arm platforms.

--- tools/v8_gypfiles/v8.gyp.orig	2021-08-03 05:54:27.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -951,6 +951,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
+        # NetBSD/arm also needs -larm.
+        ['OS == "netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm", "riscv64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
