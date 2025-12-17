$NetBSD: patch-cmake_compiler.cmake,v 1.1 2025/12/17 16:25:39 nia Exp $

Let infrastructure insert hardening options where supported.

--- cmake/compiler.cmake.orig	2025-12-17 13:33:34.185032683 +0000
+++ cmake/compiler.cmake
@@ -107,31 +107,6 @@ elseif(UNIX OR MINGW)
 			)
 		endif()
 	else()
-		if(NOT MINGW)
-			add_link_options(
-				"-Wl,-z,relro"
-				"-Wl,-z,now"
-			)
-		endif()
-
-		# Ensure _FORTIFY_SOURCE is not used in debug builds.
-		#
-		# First, ensure _FORTIFY_SOURCE is undefined.
-		# Then -- and, only for release builds -- set _FORTIFY_SOURCE=2.
-		#
-		# We can't use _FORTIFY_SOURCE in debug builds (which are built with -O0) because _FORTIFY_SOURCE=1 requires -O1 and _FORTIFY_SOURCE=2 requires -O2.
-		# Modern GLIBCs warn about this since https://sourceware.org/bugzilla/show_bug.cgi?id=13979.
-		# In Mumble builds with warnings-as-errors, this will cause build failures.
-		add_compile_options("-U_FORTIFY_SOURCE")
-
-		if(NOT MINGW)
-			add_compile_options($<$<CONFIG:Debug>:-fstack-protector>)
-		endif()
-
-		add_compile_options(
-			$<$<NOT:$<CONFIG:Debug>>:-D_FORTIFY_SOURCE=2>
-		)
-
 		add_link_options(
 			$<$<CONFIG:Debug>:-Wl,--no-add-needed>
 		)
