$NetBSD: patch-cmake_Install.cmake,v 1.3 2025/12/13 17:47:21 vins Exp $

Use pkgsrc defaults. 

--- cmake/Install.cmake.orig	2025-11-01 23:44:37.984452608 +0000
+++ cmake/Install.cmake
@@ -6,11 +6,14 @@ set(prefix ${CMAKE_INSTALL_PREFIX})
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
@@ -82,7 +85,7 @@ install(PROGRAMS ${PROGRAMS}
 
 fish_create_dirs(${sysconfdir}/fish/conf.d ${sysconfdir}/fish/completions
     ${sysconfdir}/fish/functions)
-install(FILES etc/config.fish DESTINATION ${sysconfdir}/fish/)
+install(FILES etc/config.fish DESTINATION ${egdir}/fish/)
 
 fish_create_dirs(${rel_datadir}/fish ${rel_datadir}/fish/completions
                  ${rel_datadir}/fish/functions ${rel_datadir}/fish/groff
@@ -102,7 +105,7 @@ install(FILES share/config.fish
 fish_create_dirs(${rel_datadir}/fish/vendor_completions.d ${rel_datadir}/fish/vendor_functions.d
     ${rel_datadir}/fish/vendor_conf.d)
 
-fish_try_create_dirs(${rel_datadir}/pkgconfig)
+fish_try_create_dirs(${libdir}/pkgconfig)
 configure_file(fish.pc.in fish.pc.noversion @ONLY)
 
 add_custom_command(OUTPUT fish.pc
@@ -115,7 +118,7 @@ add_custom_command(OUTPUT fish.pc
 add_custom_target(build_fish_pc ALL DEPENDS fish.pc)
 
 install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-        DESTINATION ${rel_datadir}/pkgconfig)
+        DESTINATION ${libdir}/pkgconfig)
 
 install(DIRECTORY share/completions/
         DESTINATION ${rel_datadir}/fish/completions
