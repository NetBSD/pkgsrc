$NetBSD: patch-make_autoconf_hotspot.m4,v 1.2 2026/09/05 09:44:05 tnn Exp $

Fix buildjdk targeting for 32-bit ARM.

--- make/autoconf/hotspot.m4.orig	2023-10-23 01:33:53.000000000 +0000
+++ make/autoconf/hotspot.m4
@@ -112,6 +112,8 @@ AC_DEFUN_ONCE([HOTSPOT_SETUP_MISC],
     # But when building zero, we never build any other variants so it works.
     HOTSPOT_TARGET_CPU=zero
     HOTSPOT_TARGET_CPU_ARCH=zero
+    HOTSPOT_BUILD_CPU=zero
+    HOTSPOT_BUILD_CPU_ARCH=zero
   fi
 
 
