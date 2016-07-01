$NetBSD: patch-cmake_SIPMacros.cmake,v 1.2 2016/07/01 16:15:18 bouyer Exp $

Always use MODULE with ADD_LIBRARY for modules.
This keeps it enabled whether or not APPLE is defined
since we have hacks in Makefile to override the APPLE
define when we are not building an Application Bundlea

--- cmake/SIPMacros.cmake.orig	2016-05-20 14:05:10.000000000 +0200
+++ cmake/SIPMacros.cmake	2016-06-26 14:49:35.000000000 +0200
@@ -112,11 +112,7 @@
         DEPENDS ${_abs_module_sip} ${SIP_EXTRA_FILES_DEPEND}
     )
     # not sure if type MODULE could be uses anywhere, limit to cygwin for now
-    IF (CYGWIN OR APPLE)
-        ADD_LIBRARY(${_logical_name} MODULE ${_sip_output_files} )
-    ELSE (CYGWIN OR APPLE)
-        ADD_LIBRARY(${_logical_name} SHARED ${_sip_output_files} )
-    ENDIF (CYGWIN OR APPLE)
+    ADD_LIBRARY(${_logical_name} MODULE ${_sip_output_files} )
     IF (NOT APPLE)
         TARGET_LINK_LIBRARIES(${_logical_name} ${PYTHON_LIBRARY})
     ENDIF (NOT APPLE)
