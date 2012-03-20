$NetBSD: patch-cmake_modules_FindTagLib.cmake,v 1.1 2012/03/20 10:28:29 markd Exp $

Change the string comparision operator on the TAGLIB_VERSION to a 
version comparision operator (since versions are being compared.)

--- cmake/modules/FindTaglib.cmake.orig	2011-01-11 15:58:05.000000000 +0000
+++ cmake/modules/FindTaglib.cmake
@@ -29,10 +29,10 @@ if(TAGLIBCONFIG_EXECUTABLE)
 
   exec_program(${TAGLIBCONFIG_EXECUTABLE} ARGS --version RETURN_VALUE _return_VALUE OUTPUT_VARIABLE TAGLIB_VERSION)
 
-  if(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}")
+  if(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}")
      message(STATUS "TagLib version too old: version searched :${TAGLIB_MIN_VERSION}, found ${TAGLIB_VERSION}")
      set(TAGLIB_FOUND FALSE)
-  else(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}")
+  else(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}")
 
      exec_program(${TAGLIBCONFIG_EXECUTABLE} ARGS --libs RETURN_VALUE _return_VALUE OUTPUT_VARIABLE TAGLIB_LIBRARIES)
 
@@ -42,7 +42,7 @@ if(TAGLIBCONFIG_EXECUTABLE)
         set(TAGLIB_FOUND TRUE)
      endif(TAGLIB_LIBRARIES AND TAGLIB_CFLAGS)
      string(REGEX REPLACE " *-I" ";" TAGLIB_INCLUDES "${TAGLIB_CFLAGS}")
-  endif(TAGLIB_VERSION STRLESS "${TAGLIB_MIN_VERSION}") 
+  endif(TAGLIB_VERSION VERSION_LESS "${TAGLIB_MIN_VERSION}") 
   mark_as_advanced(TAGLIB_CFLAGS TAGLIB_LIBRARIES TAGLIB_INCLUDES)
 
 else(TAGLIBCONFIG_EXECUTABLE)
