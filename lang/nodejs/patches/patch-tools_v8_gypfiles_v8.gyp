$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.3 2022/05/05 07:08:06 adam Exp $

Add -larm on netbsd arm platforms.

--- tools/v8_gypfiles/v8.gyp.orig	2022-05-03 08:18:12.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -977,6 +977,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
+        # NetBSD/arm also needs -larm.
+        ['OS == "netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm", "riscv64", "loong64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
