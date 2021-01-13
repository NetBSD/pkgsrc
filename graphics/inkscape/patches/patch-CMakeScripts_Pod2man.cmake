$NetBSD: patch-CMakeScripts_Pod2man.cmake,v 1.4 2021/01/13 11:43:34 jperkin Exp $

Fix man installation path.

--- CMakeScripts/Pod2man.cmake.orig	2020-09-07 08:57:40.000000000 +0000
+++ CMakeScripts/Pod2man.cmake
@@ -34,13 +34,13 @@ macro(pod2man PODFILE_FULL RELEASE SECTI
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}")
             set(MANFILE_FULL_GZ "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}.gz")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/${LANG}/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_MANDIR}/${LANG}/man${SECTION}")
         else()
             set(MANPAGE_TARGET "man-${NAME}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}")
             set(MANFILE_FULL_GZ "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}.gz")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_MANDIR}/man${SECTION}")
         endif()
         add_custom_command(
             OUTPUT ${MANFILE_TEMP}
@@ -56,7 +56,7 @@ macro(pod2man PODFILE_FULL RELEASE SECTI
         if(GZIP AND WITH_MANPAGE_COMPRESSION)
             add_custom_command(
                 OUTPUT ${MANFILE_FULL_GZ}
-	        COMMAND ${GZIP} -f -k --best -n "${MANFILE_FULL}"
+	        COMMAND ${GZIP} -f --best -n "${MANFILE_FULL}"
 	        DEPENDS ${MANFILE_FULL}
             )
             add_custom_target(${MANPAGE_TARGET} ALL
