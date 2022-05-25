$NetBSD: patch-make_autoconf_hotspot.m4,v 1.1 2022/05/25 06:05:34 tnn Exp $

Fix buildjdk targeting for 32-bit ARM.

--- make/autoconf/hotspot.m4.orig	2022-05-03 03:11:37.000000000 +0000
+++ make/autoconf/hotspot.m4
@@ -147,6 +147,8 @@ AC_DEFUN_ONCE([HOTSPOT_SETUP_JVM_VARIANT
     # We are guaranteed that we do not build any other variants when building zero.
     HOTSPOT_TARGET_CPU=zero
     HOTSPOT_TARGET_CPU_ARCH=zero
+    HOTSPOT_BUILD_CPU=zero
+    HOTSPOT_BUILD_CPU_ARCH=zero
   fi
 ])
 
@@ -337,6 +339,10 @@ AC_DEFUN_ONCE([HOTSPOT_SETUP_JVM_FEATURE
     HOTSPOT_TARGET_CPU=arm_64
     HOTSPOT_TARGET_CPU_ARCH=arm
   fi
+  if test "x$OPENJDK_BUILD_CPU" = xarm; then
+    HOTSPOT_BUILD_CPU=arm_32
+    HOTSPOT_BUILD_CPU_DEFINE="ARM32"
+  fi
 
   # Verify that dependencies are met for explicitly set features.
   if HOTSPOT_CHECK_JVM_FEATURE(jvmti) && ! HOTSPOT_CHECK_JVM_FEATURE(services); then
