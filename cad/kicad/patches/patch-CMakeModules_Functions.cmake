$NetBSD: patch-CMakeModules_Functions.cmake,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/Functions.cmake.orig	2014-02-14 20:02:52.000000000 +0100
+++ CMakeModules/Functions.cmake	2014-02-14 20:03:21.000000000 +0100
@@ -33,9 +33,9 @@
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
