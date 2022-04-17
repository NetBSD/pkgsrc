$NetBSD: patch-cmake_ETLInstall.cmake,v 1.3 2022/04/17 09:24:14 nia Exp $

Install man pages to PKGMANDIR.

--- cmake/ETLInstall.cmake.orig	2022-04-09 17:17:04.000000000 +0000
+++ cmake/ETLInstall.cmake
@@ -46,7 +46,7 @@ if(UNIX AND NOT APPLE)
 		DESTINATION "${INSTALL_DEFAULT_SHAREDIR}/metainfo"
 	)
 	install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs/linux/man/man6/"
-		DESTINATION "${INSTALL_DEFAULT_SHAREDIR}/man/man6"
+		DESTINATION "${CMAKE_INSTALL_MANDIR}/man6"
 	)
 	install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/docs/INSTALL.txt"
 		DESTINATION "${DOCDIR}"
