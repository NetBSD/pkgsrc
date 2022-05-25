$NetBSD: patch-make_autoconf_hotspot.m4,v 1.1 2022/05/25 06:05:34 tnn Exp $

Fix buildjdk targeting for 32-bit ARM.

--- make/autoconf/hotspot.m4.orig	2022-04-23 02:25:56.000000000 +0000
+++ make/autoconf/hotspot.m4
@@ -121,6 +121,8 @@ AC_DEFUN_ONCE([HOTSPOT_SETUP_MISC],
     # But when building zero, we never build any other variants so it works.
     HOTSPOT_TARGET_CPU=zero
     HOTSPOT_TARGET_CPU_ARCH=zero
+    HOTSPOT_BUILD_CPU=zero
+    HOTSPOT_BUILD_CPU_ARCH=zero
   fi
 
   AC_ARG_WITH([hotspot-build-time], [AS_HELP_STRING([--with-hotspot-build-time],
@@ -137,6 +139,10 @@ AC_DEFUN_ONCE([HOTSPOT_SETUP_MISC],
     HOTSPOT_TARGET_CPU=arm_32
     HOTSPOT_TARGET_CPU_DEFINE="ARM32"
   fi
+  if test "x$OPENJDK_BUILD_CPU" = xarm; then
+    HOTSPOT_BUILD_CPU=arm_32
+    HOTSPOT_BUILD_CPU_DEFINE="ARM32"
+  fi
 
   # --with-cpu-port is no longer supported
   UTIL_DEPRECATED_ARG_WITH(with-cpu-port)
