$NetBSD: patch-cmake_Install.cmake,v 1.2 2022/04/21 11:24:52 jperkin Exp $

pkgsrc-ifying:
Install config files to examples rather than etc.
Install desktop files on macOS regardless to simplify PLIST.

--- cmake/Install.cmake.orig	2022-03-25 16:22:53.000000000 +0000
+++ cmake/Install.cmake
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
@@ -170,7 +170,7 @@ if(GETTEXT_FOUND)
   endforeach()
 endif()
 
-if (NOT APPLE)
+if (1)
     install(FILES fish.desktop DESTINATION ${rel_datadir}/applications)
     install(FILES ${SPHINX_SRC_DIR}/python_docs_theme/static/fish.png DESTINATION ${rel_datadir}/pixmaps)
 endif()
