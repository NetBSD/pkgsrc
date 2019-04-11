$NetBSD: patch-cmake_ETLInstall.cmake,v 1.1 2019/04/11 20:56:34 nia Exp $

Install man pages to PKGMANDIR.

--- cmake/ETLInstall.cmake.orig	2019-01-05 19:54:35.000000000 +0000
+++ cmake/ETLInstall.cmake
@@ -37,7 +37,7 @@ if(UNIX)
 		DESTINATION "${CMAKE_INSTALL_PREFIX}/share/mime/packages"
 	)
 		install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs/linux/man/man6/"
-		DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man6"
+		DESTINATION "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_MANDIR}/man6"
 	)
 	
 	if(FEATURE_RENDERER2)
