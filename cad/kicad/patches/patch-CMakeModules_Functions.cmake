$NetBSD: patch-CMakeModules_Functions.cmake,v 1.5 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/Functions.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/Functions.cmake
@@ -40,13 +40,13 @@ function( make_lexer outputTarget inputF
             -DinputFile=${CMAKE_CURRENT_SOURCE_DIR}/${inputFile}
             -DoutHeaderFile=${CMAKE_CURRENT_BINARY_DIR}/${outHeaderFile}
             -DoutCppFile=${CMAKE_CURRENT_BINARY_DIR}/${outCppFile}
-            -P ${CMAKE_MODULE_PATH}/BuildSteps/TokenList2DsnLexer.cmake
+            -P ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/TokenList2DsnLexer.cmake
         COMMENT "TokenList2DsnLexer.cmake creating:
            ${outHeaderFile} and
            ${outCppFile} from
            ${inputFile}"
         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${inputFile}
-                ${CMAKE_MODULE_PATH}/BuildSteps/TokenList2DsnLexer.cmake
+                ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/TokenList2DsnLexer.cmake
         )
 
     target_sources( ${outputTarget} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/${outCppFile} )
@@ -84,11 +84,11 @@ function( generate_lemon_grammar TGT GRA
             -DLEMON_TEMPLATE=${LEMON_TEMPLATE}
             -DGRAMMAR_FILE=${CMAKE_CURRENT_SOURCE_DIR}/${GRAMMAR_FILE}
             -DGRAMMAR_DIR=${CMAKE_CURRENT_BINARY_DIR}/${GRAMMAR_DIR}
-            -P ${CMAKE_MODULE_PATH}/BuildSteps/LemonParserGenerator.cmake
+            -P ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/LemonParserGenerator.cmake
         COMMENT "Running Lemon on ${GRAMMAR_FILE} to generate ${GRAMMAR_DIR}/${GRAMMAR_BASE}.c"
         DEPENDS lemon
                 ${CMAKE_CURRENT_SOURCE_DIR}/${GRAMMAR_FILE}
-                ${CMAKE_MODULE_PATH}/BuildSteps/LemonParserGenerator.cmake
+                ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/LemonParserGenerator.cmake
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${GRAMMAR_DIR}
     )
 
@@ -186,13 +186,13 @@ macro( linux_metadata_translation SRC_FI
             OUTPUT ${OUT_FILE}
             DEPENDS ${SRC_FILE}
                     ${LANG_FILES}
-                    ${CMAKE_MODULE_PATH}/BuildSteps/TranslatePlatformMetadata_linux.cmake
+                    ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/TranslatePlatformMetadata_linux.cmake
             COMMAND ${CMAKE_COMMAND}
                     -DMSGFMT_EXE="${GETTEXT_MSGFMT_EXECUTABLE}"
                     -DPO_DIR="${PO_DIR}"
                     -DSRC_FILE="${SRC_FILE}"
                     -DDEST_FILE="${OUT_FILE}"
-                    -P ${CMAKE_MODULE_PATH}/BuildSteps/TranslatePlatformMetadata_linux.cmake
+                    -P ${PROJECT_SOURCE_DIR}/CMakeModules/BuildSteps/TranslatePlatformMetadata_linux.cmake
             COMMENT "Translating file ${OUT_FNAME}"
             )
     else()
