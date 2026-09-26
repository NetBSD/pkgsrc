$NetBSD: patch-make_autoconf_flags-cflags.m4,v 1.1 2026/09/26 12:54:51 tnn Exp $

We prefer to use explicit run paths.

--- make/autoconf/flags-cflags.m4.orig	2026-07-24 17:22:09.000000000 +0000
+++ make/autoconf/flags-cflags.m4
@@ -40,17 +40,17 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
     # --disable-new-dtags forces use of RPATH instead of RUNPATH for rpaths.
     # This protects internal library dependencies within the JDK from being
     # overridden using LD_LIBRARY_PATH. See JDK-8326891 for more information.
-    SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1 -Wl,--disable-new-dtags'
-    SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
+    SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/${JVM_VARIANT_MAIN}'
+    SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
     SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
 
   elif test "x$TOOLCHAIN_TYPE" = xclang; then
     if test "x$OPENJDK_TARGET_OS" = xmacosx; then
       # Linking is different on MacOSX
       SHARED_LIBRARY_FLAGS="-dynamiclib -compatibility_version 1.0.0 -current_version 1.0.0"
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,@loader_path$(or [$]1,/.)'
-      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
-      SET_SHARED_LIBRARY_NAME='-Wl,-install_name,@rpath/[$]1'
+      SET_EXECUTABLE_ORIGIN=''
+      SET_SHARED_LIBRARY_ORIGIN=''
+      SET_SHARED_LIBRARY_NAME='-Wl,-install_name,@PREFIX@/java/@JAVA_NAME@/lib/$(patsubst libjvm.%,${JVM_VARIANT_MAIN}/libjvm.%,[$]1)'
 
     elif test "x$OPENJDK_TARGET_OS" = xaix; then
       # Linking is different on aix
@@ -62,19 +62,12 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
     else
       # Default works for linux, might work on other platforms as well.
       SHARED_LIBRARY_FLAGS='-shared'
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
+      SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/${JVM_VARIANT_MAIN}'
       if test "x$OPENJDK_TARGET_OS" = xlinux; then
         SET_EXECUTABLE_ORIGIN="$SET_EXECUTABLE_ORIGIN -Wl,--disable-new-dtags"
       fi
       SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
-
-      # arm specific settings
-      if test "x$OPENJDK_TARGET_CPU" = "xarm"; then
-        # '-Wl,-z,origin' isn't used on arm.
-        SET_SHARED_LIBRARY_ORIGIN='-Wl,-rpath,\$$$$ORIGIN[$]1'
-      else
-        SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
-      fi
+      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
     fi
 
   elif test "x$TOOLCHAIN_TYPE" = xmicrosoft; then
