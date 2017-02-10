$NetBSD: patch-CMakeScripts_Pod2man.cmake,v 1.1 2017/02/10 05:51:43 adam Exp $

Fix man installation path.

--- CMakeScripts/Pod2man.cmake.orig	2017-02-08 19:36:52.000000000 +0000
+++ CMakeScripts/Pod2man.cmake
@@ -48,7 +48,7 @@ macro(pod2man PODFILE_FULL RELEASE SECTI
         )
         install(
             FILES ${MANFILE_FULL}
-            DESTINATION ${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/man${SECTION}
+            DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man${SECTION}
         )
     endif()
 endmacro(pod2man PODFILE NAME SECTION CENTER)
