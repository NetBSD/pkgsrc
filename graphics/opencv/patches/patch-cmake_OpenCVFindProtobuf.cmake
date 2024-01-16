$NetBSD: patch-cmake_OpenCVFindProtobuf.cmake,v 1.1 2024/01/16 19:23:05 adam Exp $

Support protobuf v22 and later.
https://github.com/opencv/opencv/pull/24372

--- cmake/OpenCVFindProtobuf.cmake.orig	2023-06-27 11:29:13.000000000 +0000
+++ cmake/OpenCVFindProtobuf.cmake
@@ -30,8 +30,14 @@ if(BUILD_PROTOBUF)
   set(Protobuf_LIBRARIES "libprotobuf")
   set(HAVE_PROTOBUF TRUE)
 else()
+  # we still need this for command PROTOBUF_GENERATE_CPP.
+  set(protobuf_MODULE_COMPATIBLE ON)
+
   unset(Protobuf_VERSION CACHE)
-  find_package(Protobuf QUIET)
+  find_package(Protobuf QUIET CONFIG)
+  if(NOT Protobuf_FOUND)
+    find_package(Protobuf QUIET)
+  endif()
 
   # Backwards compatibility
   # Define camel case versions of input variables
@@ -67,6 +73,20 @@ else()
   endif()
 endif()
 
+# See https://github.com/opencv/opencv/issues/24369
+# In Protocol Buffers v22.0 and later drops C++11 support and depends abseil-cpp.
+#   Details: https://protobuf.dev/news/2022-08-03/
+# And if std::text_view is in abseil-cpp requests C++17 and later.
+
+if(HAVE_PROTOBUF)
+  if(NOT (Protobuf_VERSION VERSION_LESS 22))
+    if((CMAKE_CXX_STANDARD EQUAL 98) OR (CMAKE_CXX_STANDARD LESS 17))
+      message(STATUS "CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD} is too old to support protobuf(${Protobuf_VERSION}) and/or abseil-cpp. Use C++17 or later. Turning HAVE_PROTOBUF off")
+      set(HAVE_PROTOBUF FALSE)
+    endif()
+  endif()
+endif()
+
 if(HAVE_PROTOBUF AND PROTOBUF_UPDATE_FILES AND NOT COMMAND PROTOBUF_GENERATE_CPP)
   message(FATAL_ERROR "Can't configure protobuf dependency (BUILD_PROTOBUF=${BUILD_PROTOBUF} PROTOBUF_UPDATE_FILES=${PROTOBUF_UPDATE_FILES})")
 endif()
@@ -74,15 +94,20 @@ endif()
 if(HAVE_PROTOBUF)
   list(APPEND CUSTOM_STATUS protobuf)
   if(NOT BUILD_PROTOBUF)
+    unset( __location)
     if(TARGET "${Protobuf_LIBRARIES}")
       get_target_property(__location "${Protobuf_LIBRARIES}" IMPORTED_LOCATION_RELEASE)
       if(NOT __location)
         get_target_property(__location "${Protobuf_LIBRARIES}" IMPORTED_LOCATION)
       endif()
-    elseif(Protobuf_LIBRARY)
-      set(__location "${Protobuf_LIBRARY}")
-    else()
-      set(__location "${Protobuf_LIBRARIES}")
+    endif()
+
+    if(NOT __location)
+      if(Protobuf_LIBRARY)
+        set(__location "${Protobuf_LIBRARY}")
+      else()
+        set(__location "${Protobuf_LIBRARIES}")
+      endif()
     endif()
   endif()
   list(APPEND CUSTOM_STATUS_protobuf "    Protobuf:"
