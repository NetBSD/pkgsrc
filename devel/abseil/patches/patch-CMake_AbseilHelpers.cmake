$NetBSD: patch-CMake_AbseilHelpers.cmake,v 1.1 2024/12/25 20:22:48 schmonz Exp $

Fix shell option group handling in pkgconfig files.
From upstream commit bd0c9c5

--- CMake/AbseilHelpers.cmake.orig	2024-12-25 20:10:10.414504667 +0000
+++ CMake/AbseilHelpers.cmake
@@ -186,15 +186,15 @@ function(absl_cc_library)
         endif()
       endif()
     endforeach()
-    set(skip_next_cflag OFF)
     foreach(cflag ${ABSL_CC_LIB_COPTS})
-      if(skip_next_cflag)
-        set(skip_next_cflag OFF)
-      elseif(${cflag} MATCHES "^-Xarch_")
+      # Strip out the CMake-specific `SHELL:` prefix, which is used to construct
+      # a group of space-separated options.
+      # https://cmake.org/cmake/help/v3.30/command/target_compile_options.html#option-de-duplication
+      string(REGEX REPLACE "^SHELL:" "" cflag "${cflag}")
+      if(${cflag} MATCHES "^-Xarch_")
         # An -Xarch_ flag implies that its successor only applies to the
-        # specified platform. Filter both of them out before the successor
-        # reaches the "^-m" filter.
-        set(skip_next_cflag ON)
+        # specified platform. Such option groups are each specified in a single
+        # `SHELL:`-prefixed string in the COPTS list, which we simply ignore.
       elseif(${cflag} MATCHES "^(-Wno|/wd)")
         # These flags are needed to suppress warnings that might fire in our headers.
         set(PC_CFLAGS "${PC_CFLAGS} ${cflag}")
