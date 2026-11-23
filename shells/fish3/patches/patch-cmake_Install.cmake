$NetBSD: patch-cmake_Install.cmake,v 1.2 2026/11/23 07:46:21 wiz Exp $

pkgsrc-ifying:
Install config files to examples rather than etc.
Install desktop files on macOS regardless to simplify PLIST.

Fix installation with cmake 4.5.
https://github.com/fish-shell/fish-shell/commit/95dccbe55eefe73e526563296beded4a8407b8a8

--- cmake/Install.cmake.orig	2024-03-19 03:40:45.000000000 +0000
+++ cmake/Install.cmake
@@ -70,7 +70,7 @@ function(FISH_TRY_CREATE_DIRS)
     else()
       set(abs_dir "\$ENV{DESTDIR}${dir}")
     endif()
-    install(SCRIPT CODE "EXECUTE_PROCESS(COMMAND mkdir -p ${abs_dir} OUTPUT_QUIET ERROR_QUIET)
+    install(CODE "EXECUTE_PROCESS(COMMAND mkdir -p ${abs_dir} OUTPUT_QUIET ERROR_QUIET)
                          execute_process(COMMAND chmod 755 ${abs_dir} OUTPUT_QUIET ERROR_QUIET)
                         ")
   endforeach()
@@ -81,9 +81,9 @@ install(TARGETS ${PROGRAMS}
                     GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
         DESTINATION ${bindir})
 
-fish_create_dirs(${sysconfdir}/fish/conf.d ${sysconfdir}/fish/completions
-    ${sysconfdir}/fish/functions)
-install(FILES etc/config.fish DESTINATION ${sysconfdir}/fish/)
+fish_create_dirs(${rel_datadir}/examples/fish/conf.d ${rel_datadir}/examples/fish/completions
+    ${rel_datadir}/examples/fish/functions)
+install(FILES etc/config.fish DESTINATION ${rel_datadir}/examples/fish/)
 
 fish_create_dirs(${rel_datadir}/fish ${rel_datadir}/fish/completions
                  ${rel_datadir}/fish/functions ${rel_datadir}/fish/groff
@@ -168,7 +168,7 @@ endif()
   endforeach()
 endif()
 
-if (NOT APPLE)
+if (1)
     install(FILES fish.desktop DESTINATION ${rel_datadir}/applications)
     install(FILES ${SPHINX_SRC_DIR}/python_docs_theme/static/fish.png DESTINATION ${rel_datadir}/pixmaps)
 endif()
