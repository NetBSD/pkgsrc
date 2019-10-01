$NetBSD: patch-make_autoconf_flags-cflags.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

We prefer to use explicit run paths.

--- make/autoconf/flags-cflags.m4.orig	2019-09-19 12:22:38.000000000 +0000
+++ make/autoconf/flags-cflags.m4
@@ -39,8 +39,8 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
 
     # Default works for linux, might work on other platforms as well.
     SHARED_LIBRARY_FLAGS='-shared'
-    SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
-    SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
+    SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
+    SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
     SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
     SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
 
@@ -58,17 +58,10 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
     else
       # Default works for linux, might work on other platforms as well.
       SHARED_LIBRARY_FLAGS='-shared'
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
+      SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
+      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
       SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
       SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
-
-      # arm specific settings
-      if test "x$OPENJDK_TARGET_CPU" = "xarm"; then
-        # '-Wl,-z,origin' isn't used on arm.
-        SET_SHARED_LIBRARY_ORIGIN='-Wl,-rpath,\$$$$ORIGIN[$]1'
-      else
-        SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
-      fi
     fi
 
   elif test "x$TOOLCHAIN_TYPE" = xsolstudio; then
