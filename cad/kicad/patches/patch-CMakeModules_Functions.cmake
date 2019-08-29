$NetBSD: patch-CMakeModules_Functions.cmake,v 1.4 2019/08/29 15:36:40 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/Functions.cmake.orig	2019-08-04 18:36:25.000000000 +0200
+++ CMakeModules/Functions.cmake	2019-08-29 13:23:28.260311176 +0200
@@ -40,7 +40,7 @@
             -DinputFile=${inputFile}
             -DoutHeaderFile=${outHeaderFile}
             -DoutCppFile=${outCppFile}
-            -P ${CMAKE_MODULE_PATH}/TokenList2DsnLexer.cmake
+            -P ${PROJECT_SOURCE_DIR}/CMakeModules/TokenList2DsnLexer.cmake
         COMMENT "TokenList2DsnLexer.cmake creating:
            ${outHeaderFile} and
            ${outCppFile} from
@@ -49,7 +49,7 @@
 
     add_custom_target( ${outputTarget}
         DEPENDS ${outHeaderFile} ${outCppFile}
-                ${CMAKE_MODULE_PATH}/TokenList2DsnLexer.cmake
+                ${PROJECT_SOURCE_DIR}/CMakeModules/TokenList2DsnLexer.cmake
         )
 
     # extra_args, if any, are treated as source files (typically headers) which
