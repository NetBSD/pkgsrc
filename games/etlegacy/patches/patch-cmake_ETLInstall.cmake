$NetBSD: patch-cmake_ETLInstall.cmake,v 1.2 2021/12/09 16:10:59 nia Exp $

Install man pages to PKGMANDIR.

--- cmake/ETLInstall.cmake.orig	2021-11-01 20:57:18.000000000 +0000
+++ cmake/ETLInstall.cmake
@@ -42,7 +42,7 @@ if(UNIX AND NOT APPLE)
 		DESTINATION "${INSTALL_DEFAULT_SHAREDIR}/metainfo"
 	)
 	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs/linux/man/man6/"
-		DESTINATION "${INSTALL_DEFAULT_SHAREDIR}/man/man6"
+		DESTINATION "${CMAKE_INSTALL_MANDIR}/man6"
 	)
 	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/docs/INSTALL.txt"
 		DESTINATION "${INSTALL_DEFAULT_SHAREDIR}/doc/etlegacy"
