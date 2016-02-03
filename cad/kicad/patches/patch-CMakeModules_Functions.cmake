$NetBSD: patch-CMakeModules_Functions.cmake,v 1.2 2016/02/03 19:34:33 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/Functions.cmake.orig	2015-12-14 20:13:21.000000000 +0100
+++ CMakeModules/Functions.cmake	2015-12-14 20:14:40.000000000 +0100
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
