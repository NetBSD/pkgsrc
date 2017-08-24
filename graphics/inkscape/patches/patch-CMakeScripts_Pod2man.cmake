$NetBSD: patch-CMakeScripts_Pod2man.cmake,v 1.2 2017/08/24 09:07:12 jperkin Exp $

Fix man installation path.

--- CMakeScripts/Pod2man.cmake.orig	2017-02-08 19:36:52.000000000 +0000
+++ CMakeScripts/Pod2man.cmake
@@ -48,7 +48,7 @@ macro(pod2man PODFILE_FULL RELEASE SECTI
         )
         install(
             FILES ${MANFILE_FULL}
-            DESTINATION ${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/man${SECTION}
+            DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_MANDIR}/man${SECTION}
         )
     endif()
 endmacro(pod2man PODFILE NAME SECTION CENTER)
