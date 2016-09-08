$NetBSD: patch-CMakeModules_Functions.cmake,v 1.3 2016/09/08 09:32:28 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/Functions.cmake.orig	2016-09-03 22:47:43.000000000 +0200
+++ CMakeModules/Functions.cmake	2016-09-07 18:48:08.000000000 +0200
@@ -36,9 +36,9 @@
             -DinputFile=${inputFile}
             -DoutHeaderFile=${outHeaderFile}
             -DoutCppFile=${outCppFile}
-            -P ${CMAKE_MODULE_PATH}/TokenList2DsnLexer.cmake
+            -P ${PROJECT_SOURCE_DIR}/CMakeModules/TokenList2DsnLexer.cmake
         DEPENDS ${inputFile}
-                ${CMAKE_MODULE_PATH}/TokenList2DsnLexer.cmake
+                ${PROJECT_SOURCE_DIR}/CMakeModules/TokenList2DsnLexer.cmake
         COMMENT "TokenList2DsnLexer.cmake creating:
            ${outHeaderFile} and
            ${outCppFile} from
