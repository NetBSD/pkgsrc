$NetBSD: patch-cmake_Install.cmake,v 1.6 2026/08/09 16:45:24 wiz Exp $

Use pkgsrc defaults. 

--- cmake/Install.cmake.orig	2026-07-13 23:26:44.000000000 +0000
+++ cmake/Install.cmake
@@ -4,11 +4,14 @@ set(mandir ${CMAKE_INSTALL_MANDIR})
 set(bindir ${CMAKE_INSTALL_BINDIR})
 set(sysconfdir ${CMAKE_INSTALL_SYSCONFDIR})
 set(mandir ${CMAKE_INSTALL_MANDIR})
+set(libdir ${CMAKE_INSTALL_LIBDIR})
 
+
 set(datadir ${CMAKE_INSTALL_FULL_DATADIR})
 file(RELATIVE_PATH rel_datadir ${CMAKE_INSTALL_PREFIX} ${datadir})
 
 set(docdir ${CMAKE_INSTALL_DOCDIR})
+set(egdir "${datadir}/examples")
 
 set(rel_completionsdir "fish/vendor_completions.d")
 set(rel_functionsdir "fish/vendor_functions.d")
@@ -101,7 +104,7 @@ fish_create_dirs(${sysconfdir}/fish/conf.d ${sysconfdi
 
 fish_create_dirs(${sysconfdir}/fish/conf.d ${sysconfdir}/fish/completions
     ${sysconfdir}/fish/functions)
-install(FILES etc/config.fish DESTINATION ${sysconfdir}/fish/)
+install(FILES etc/config.fish DESTINATION ${egdir}/fish/)
 
 fish_create_dirs(
     ${rel_datadir}/fish
@@ -134,7 +137,7 @@ install(
 
 install(
     FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-    DESTINATION ${rel_datadir}/pkgconfig
+    DESTINATION ${libdir}/pkgconfig
 )
 
 # CONDEMNED_PAGE is managed by the conditional above
