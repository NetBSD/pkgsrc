$NetBSD: patch-cmake_SIPMacros.cmake,v 1.1 2016/02/02 04:33:58 dbj Exp $

Always use MODULE with ADD_LIBRARY for modules.
This keeps it enabled whether or not APPLE is defined
since we have hacks in Makefile to override the APPLE
define when we are not building an Application Bundlea

--- cmake/SIPMacros.cmake.orig	2016-02-01 04:15:41.000000000 +0000
+++ cmake/SIPMacros.cmake
@@ -108,12 +108,7 @@ MACRO(ADD_SIP_PYTHON_MODULE MODULE_NAME 
         COMMAND ${SIP_BINARY_PATH} ${_sip_tags} -w -e ${_sip_x} ${SIP_EXTRA_OPTIONS} -j ${SIP_CONCAT_PARTS} -c ${CMAKE_CURRENT_BINARY_DIR}/${_module_path} ${_sip_includes} ${_abs_module_sip}
         DEPENDS ${_abs_module_sip} ${SIP_EXTRA_FILES_DEPEND}
     )
-    # not sure if type MODULE could be uses anywhere, limit to cygwin for now
-    IF (CYGWIN OR APPLE)
-        ADD_LIBRARY(${_logical_name} MODULE ${_sip_output_files} )
-    ELSE (CYGWIN OR APPLE)
-        ADD_LIBRARY(${_logical_name} SHARED ${_sip_output_files} )
-    ENDIF (CYGWIN OR APPLE)
+    ADD_LIBRARY(${_logical_name} MODULE ${_sip_output_files} )
     IF (NOT APPLE)
         TARGET_LINK_LIBRARIES(${_logical_name} ${PYTHON_LIBRARY})
     ENDIF (NOT APPLE)
