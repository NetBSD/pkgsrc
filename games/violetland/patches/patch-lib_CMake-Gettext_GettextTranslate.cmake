$NetBSD: patch-lib_CMake-Gettext_GettextTranslate.cmake,v 1.1 2016/09/11 14:44:30 kamil Exp $

--- lib/CMake-Gettext/GettextTranslate.cmake.orig	2016-07-27 09:04:19.000000000 +0000
+++ lib/CMake-Gettext/GettextTranslate.cmake
@@ -189,8 +189,6 @@ macro(GettextTranslate)
       --msgid-bugs-address="${MAKEVAR_MSGID_BUGS_ADDRESS}"
       --directory=${MAKEVAR_top_builddir}
       --files-from=${CMAKE_CURRENT_BINARY_DIR}/POTFILES
-      --package-version=${VERSION}
-      --package-name=${CMAKE_PROJECT_NAME}
     DEPENDS ${source_translatable}
     ${CMAKE_CURRENT_SOURCE_DIR}/POTFILES.in
     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
