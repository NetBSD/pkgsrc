$NetBSD: patch-cmake_Modules_Pod2Man.cmake,v 1.1 2022/09/27 01:20:39 gdt Exp $

Change man install path to pkgsrc norms.

Not reported upstream until we are caught up.  Then, the bug is not
the value, but that it isn't configurable via a cmake command-line
argument.

--- cmake/Modules/Pod2Man.cmake.orig	2019-02-22 15:38:47.000000000 +0000
+++ cmake/Modules/Pod2Man.cmake
@@ -58,7 +58,7 @@ MACRO(POD2MAN PODFILE MANFILE SECTION)
 
 	INSTALL(
 		FILES ${CMAKE_CURRENT_BINARY_DIR}/${MANFILE}.${SECTION}.gz
-		DESTINATION share/man/man${SECTION}
+		DESTINATION man/man${SECTION}
     	)
 ENDMACRO(POD2MAN PODFILE MANFILE SECTION)
 
