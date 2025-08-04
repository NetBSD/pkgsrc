$NetBSD: patch-make_autoconf_flags-cflags.m4,v 1.5 2025/08/04 13:22:06 pho Exp $

We prefer to use explicit run paths.
Add lib/jli to link libjli.so dynamically. Fix runtime error of Bazel.
Require c++11 as we have some patches using it.

--- make/autoconf/flags-cflags.m4.orig	2025-04-19 23:57:10.000000000 +0000
+++ make/autoconf/flags-cflags.m4
@@ -42,8 +42,8 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
     # --disable-new-dtags forces use of RPATH instead of RUNPATH for rpaths.
     # This protects internal library dependencies within the JDK from being
     # overridden using LD_LIBRARY_PATH. See JDK-8326891 for more information.
-    SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1 -Wl,--disable-new-dtags'
-    SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
+    SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/jli'
+    SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
     SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
     SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
 
@@ -61,20 +61,13 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
     else
       # Default works for linux, might work on other platforms as well.
       SHARED_LIBRARY_FLAGS='-shared'
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
+      SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
+      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
       if test "x$OPENJDK_TARGET_OS" = xlinux; then
         SET_EXECUTABLE_ORIGIN="$SET_EXECUTABLE_ORIGIN -Wl,--disable-new-dtags"
       fi
       SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
       SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
-
-      # arm specific settings
-      if test "x$OPENJDK_TARGET_CPU" = "xarm" && test "x$OPENJDK_TARGET_OS" = xlinux; then
-        # '-Wl,-z,origin' isn't used on arm.
-        SET_SHARED_LIBRARY_ORIGIN='-Wl,-rpath,\$$$$ORIGIN[$]1'
-      else
-        SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
-      fi
     fi
 
   elif test "x$TOOLCHAIN_TYPE" = xsolstudio; then
@@ -566,7 +559,7 @@ AC_DEFUN([FLAGS_SETUP_CFLAGS_HELPER],
       TOOLCHAIN_CFLAGS_JDK="-pipe"
       TOOLCHAIN_CFLAGS_JDK_CONLY="-fno-strict-aliasing" # technically NOT for CXX
 
-      CXXSTD_CXXFLAG="-std=gnu++98"
+      CXXSTD_CXXFLAG="-std=gnu++11"
       FLAGS_CXX_COMPILER_CHECK_ARGUMENTS(ARGUMENT: [$CXXSTD_CXXFLAG -Werror],
     						   IF_FALSE: [CXXSTD_CXXFLAG=""])
       TOOLCHAIN_CFLAGS_JDK_CXXONLY="$CXXSTD_CXXFLAG"
@@ -817,7 +810,7 @@ AC_DEFUN([FLAGS_SETUP_CFLAGS_CPU_DEP],
       $1_CFLAGS_CPU_JDK="${$1_CFLAGS_CPU_JDK} -fno-omit-frame-pointer"
     fi
 
-    $1_CXXSTD_CXXFLAG="-std=gnu++98"
+    $1_CXXSTD_CXXFLAG="-std=gnu++11"
     FLAGS_CXX_COMPILER_CHECK_ARGUMENTS(ARGUMENT: [${$1_CXXSTD_CXXFLAG} -Werror],
         PREFIX: $3, IF_FALSE: [$1_CXXSTD_CXXFLAG=""])
     $1_TOOLCHAIN_CFLAGS_JDK_CXXONLY="${$1_CXXSTD_CXXFLAG}"
