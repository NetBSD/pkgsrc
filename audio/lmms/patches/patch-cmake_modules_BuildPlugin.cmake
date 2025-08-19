$NetBSD: patch-cmake_modules_BuildPlugin.cmake,v 1.1 2025/08/19 07:20:26 wiz Exp $

cmake 4 compatibility using arch patch.
https://gitlab.archlinux.org/archlinux/packaging/packages/lmms/-/blob/main/cmake-4.patch?ref_type=heads

--- cmake/modules/BuildPlugin.cmake.orig	2018-11-03 01:43:42.000000000 +0000
+++ cmake/modules/BuildPlugin.cmake
@@ -27,7 +27,7 @@ MACRO(BUILD_PLUGIN PLUGIN_NAME)
 
 		SET(ER_H "${CMAKE_CURRENT_BINARY_DIR}/embedded_resources.h")
 		ADD_CUSTOM_COMMAND(OUTPUT ${ER_H}
-			COMMAND ${BIN2RES}
+			COMMAND bin2res
 			ARGS ${PLUGIN_EMBEDDED_RESOURCES} > "${ER_H}"
 			DEPENDS bin2res)
 	ENDIF(ER_LEN)
