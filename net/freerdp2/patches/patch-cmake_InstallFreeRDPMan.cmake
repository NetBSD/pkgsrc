$NetBSD: patch-cmake_InstallFreeRDPMan.cmake,v 1.2 2022/08/29 10:36:51 nia Exp $

Install man pages to CMAKE_INSTALL_MANDIR on all OSes, per pkgsrc policy.

https://github.com/FreeRDP/FreeRDP/commit/8f44b9cf87d85de5cc2db0cf1d61771748f3249b

--- cmake/InstallFreeRDPMan.cmake.orig	2021-03-15 12:29:35.000000000 +0000
+++ cmake/InstallFreeRDPMan.cmake
@@ -1,9 +1,7 @@
+include(GNUInstallDirs)
+
 function(install_freerdp_man manpage section)
  if(WITH_MANPAGES)
-   if(OPENBSD OR FREEBSD)
-       install(FILES ${manpage} DESTINATION man/man${section})
-    else()
-       install(FILES ${manpage} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/man/man${section})
-   endif()
+   install(FILES ${manpage} DESTINATION ${CMAKE_INSTALL_MANDIR}/man${section})
  endif()
 endfunction()
