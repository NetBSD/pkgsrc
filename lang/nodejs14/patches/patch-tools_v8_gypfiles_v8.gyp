$NetBSD: patch-tools_v8_gypfiles_v8.gyp,v 1.1 2022/03/30 06:51:31 adam Exp $

Add -larm on netbsd arm platforms.

--- tools/v8_gypfiles/v8.gyp.orig	2020-10-07 10:47:43.000000000 -0700
+++ tools/v8_gypfiles/v8.gyp	2020-10-17 13:16:57.485883322 -0700
@@ -903,6 +903,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
+        # NetBSD/arm also needs -larm.
+        ['OS == "netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
