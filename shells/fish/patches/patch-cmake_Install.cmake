$NetBSD: patch-cmake_Install.cmake,v 1.1 2021/03/05 08:47:29 nia Exp $

pkgsrc-ifying:
Install config files to examples rather than etc.

--- cmake/Install.cmake.orig	2021-03-01 12:47:02.000000000 +0000
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
