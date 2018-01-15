$NetBSD: patch-Modules_FindBoost.cmake,v 1.3 2018/01/15 18:12:41 minskim Exp $

Add Boost 1.66.0 support.
(https://gitlab.kitware.com/cmake/cmake/merge_requests/1625

--- Modules/FindBoost.cmake.orig	2017-12-13 13:25:23.000000000 +0000
+++ Modules/FindBoost.cmake
@@ -797,9 +797,8 @@ function(_Boost_COMPONENT_DEPENDENCIES c
       set(_Boost_WAVE_DEPENDENCIES filesystem system serialization thread chrono date_time atomic)
       set(_Boost_WSERIALIZATION_DEPENDENCIES serialization)
     endif()
-    if(NOT Boost_VERSION VERSION_LESS 106600)
+    if(NOT Boost_VERSION VERSION_LESS 106700)
       message(WARNING "New Boost version may have incorrect or missing dependencies and imported targets")
-      set(_Boost_IMPORTED_TARGETS FALSE)
     endif()
   endif()
 
@@ -831,8 +830,8 @@ function(_Boost_COMPONENT_HEADERS compon
   set(_Boost_CONTAINER_HEADERS           "boost/container/container_fwd.hpp")
   set(_Boost_CONTEXT_HEADERS             "boost/context/all.hpp")
   set(_Boost_COROUTINE_HEADERS           "boost/coroutine/all.hpp")
-  set(_Boost_EXCEPTION_HEADERS           "boost/exception/exception.hpp")
   set(_Boost_DATE_TIME_HEADERS           "boost/date_time/date.hpp")
+  set(_Boost_EXCEPTION_HEADERS           "boost/exception/exception.hpp")
   set(_Boost_FIBER_HEADERS               "boost/fiber/all.hpp")
   set(_Boost_FILESYSTEM_HEADERS          "boost/filesystem/path.hpp")
   set(_Boost_GRAPH_HEADERS               "boost/graph/adjacency_list.hpp")
@@ -931,8 +930,8 @@ endfunction()
 # `${Boost_ROOT}/libs/fiber/build/Jamfile.v2`.
 #
 function(_Boost_COMPILER_FEATURES component _ret)
-  # Boost >= 1.62 and < 1.65
-  if(NOT Boost_VERSION VERSION_LESS 106200 AND Boost_VERSION VERSION_LESS 106500)
+  # Boost >= 1.62 and < 1.67
+  if(NOT Boost_VERSION VERSION_LESS 106200 AND Boost_VERSION VERSION_LESS 106700)
     set(_Boost_FIBER_COMPILER_FEATURES
         cxx_alias_templates
         cxx_auto_type
@@ -1038,7 +1037,7 @@ else()
   # _Boost_COMPONENT_HEADERS.  See the instructions at the top of
   # _Boost_COMPONENT_DEPENDENCIES.
   set(_Boost_KNOWN_VERSIONS ${Boost_ADDITIONAL_VERSIONS}
-    "1.65.1" "1.65.0" "1.65"
+    "1.66.0" "1.66" "1.65.1" "1.65.0" "1.65"
     "1.64.0" "1.64" "1.63.0" "1.63" "1.62.0" "1.62" "1.61.0" "1.61" "1.60.0" "1.60"
     "1.59.0" "1.59" "1.58.0" "1.58" "1.57.0" "1.57" "1.56.0" "1.56" "1.55.0" "1.55"
     "1.54.0" "1.54" "1.53.0" "1.53" "1.52.0" "1.52" "1.51.0" "1.51"
@@ -1385,8 +1384,11 @@ if(Boost_DEBUG)
 endif()
 
 #======================
-# Systematically build up the Boost ABI tag
-# http://boost.org/doc/libs/1_41_0/more/getting_started/windows.html#library-naming
+# Systematically build up the Boost ABI tag for the 'tagged' and 'versioned' layouts
+# http://boost.org/doc/libs/1_66_0/more/getting_started/windows.html#library-naming
+# http://boost.org/doc/libs/1_66_0/boost/config/auto_link.hpp
+# http://boost.org/doc/libs/1_66_0/tools/build/src/tools/common.jam
+# http://boost.org/doc/libs/1_66_0/boostcpp.jam
 set( _boost_RELEASE_ABI_TAG "-")
 set( _boost_DEBUG_ABI_TAG   "-")
 # Key       Use this library when:
@@ -1418,11 +1420,40 @@ if(Boost_USE_STLPORT)
   string(APPEND _boost_DEBUG_ABI_TAG "p")
 endif()
 #  n        using the STLport deprecated "native iostreams" feature
+#           removed from the documentation in 1.43.0 but still present in
+#           boost/config/auto_link.hpp
 if(Boost_USE_STLPORT_DEPRECATED_NATIVE_IOSTREAMS)
   string(APPEND _boost_RELEASE_ABI_TAG "n")
   string(APPEND _boost_DEBUG_ABI_TAG "n")
 endif()
 
+#  -x86     Architecture and address model tag
+#           First character is the architecture, then word-size, either 32 or 64
+#           Only used in 'versioned' layout, added in Boost 1.66.0
+set(_boost_ARCHITECTURE_TAG "")
+# {CMAKE_CXX_COMPILER_ARCHITECTURE_ID} is not currently set for all compilers
+if(NOT "x${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "x" AND NOT Boost_VERSION VERSION_LESS 106600)
+  string(APPEND _boost_ARCHITECTURE_TAG "-")
+  # This needs to be kept in-sync with the section of CMakePlatformId.h.in
+  # inside 'defined(_WIN32) && defined(_MSC_VER)'
+  if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL "IA64")
+    string(APPEND _boost_ARCHITECTURE_TAG "i")
+  elseif(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL "X86"
+            OR ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL "x64")
+    string(APPEND _boost_ARCHITECTURE_TAG "x")
+  elseif(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} MATCHES "^ARM")
+    string(APPEND _boost_ARCHITECTURE_TAG "a")
+  elseif(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL "MIPS")
+    string(APPEND _boost_ARCHITECTURE_TAG "m")
+  endif()
+
+  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
+    string(APPEND _boost_ARCHITECTURE_TAG "64")
+  else()
+    string(APPEND _boost_ARCHITECTURE_TAG "32")
+  endif()
+endif()
+
 if(Boost_DEBUG)
   message(STATUS "[ ${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE} ] "
     "_boost_RELEASE_ABI_TAG = ${_boost_RELEASE_ABI_TAG}")
@@ -1470,6 +1501,7 @@ foreach(c DEBUG RELEASE)
       ${Boost_INCLUDE_DIR}/stage/lib
       )
     _Boost_UPDATE_WINDOWS_LIBRARY_SEARCH_DIRS_WITH_PREBUILT_PATHS(_boost_LIBRARY_SEARCH_DIRS_${c} "${Boost_INCLUDE_DIR}/..")
+    _Boost_UPDATE_WINDOWS_LIBRARY_SEARCH_DIRS_WITH_PREBUILT_PATHS(_boost_LIBRARY_SEARCH_DIRS_${c} "${Boost_INCLUDE_DIR}")
     if( Boost_NO_SYSTEM_PATHS )
       list(APPEND _boost_LIBRARY_SEARCH_DIRS_${c} NO_CMAKE_SYSTEM_PATH NO_SYSTEM_ENVIRONMENT_PATH)
     else()
@@ -1616,22 +1648,22 @@ foreach(COMPONENT ${Boost_FIND_COMPONENT
   unset(_boost_RELEASE_NAMES)
   foreach(compiler IN LISTS _boost_COMPILER)
     list(APPEND _boost_RELEASE_NAMES
-      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG}-${Boost_LIB_VERSION}
+      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
       ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG} )
   endforeach()
   list(APPEND _boost_RELEASE_NAMES
-    ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG}-${Boost_LIB_VERSION}
+    ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
     ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_ABI_TAG}
     ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT} )
   if(_boost_STATIC_RUNTIME_WORKAROUND)
     set(_boost_RELEASE_STATIC_ABI_TAG "-s${_boost_RELEASE_ABI_TAG}")
     foreach(compiler IN LISTS _boost_COMPILER)
       list(APPEND _boost_RELEASE_NAMES
-        ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG}-${Boost_LIB_VERSION}
+        ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
         ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG} )
     endforeach()
     list(APPEND _boost_RELEASE_NAMES
-      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG}-${Boost_LIB_VERSION}
+      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
       ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_RELEASE_STATIC_ABI_TAG} )
   endif()
   if(Boost_THREADAPI AND ${COMPONENT} STREQUAL "thread")
@@ -1666,11 +1698,11 @@ foreach(COMPONENT ${Boost_FIND_COMPONENT
   unset(_boost_DEBUG_NAMES)
   foreach(compiler IN LISTS _boost_COMPILER)
     list(APPEND _boost_DEBUG_NAMES
-      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG}-${Boost_LIB_VERSION}
+      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
       ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG} )
   endforeach()
   list(APPEND _boost_DEBUG_NAMES
-    ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG}-${Boost_LIB_VERSION}
+    ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
     ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_ABI_TAG}
     ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}
     ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT} )
@@ -1678,11 +1710,11 @@ foreach(COMPONENT ${Boost_FIND_COMPONENT
     set(_boost_DEBUG_STATIC_ABI_TAG "-s${_boost_DEBUG_ABI_TAG}")
     foreach(compiler IN LISTS _boost_COMPILER)
       list(APPEND _boost_DEBUG_NAMES
-        ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG}-${Boost_LIB_VERSION}
+        ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
         ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${compiler}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG} )
     endforeach()
     list(APPEND _boost_DEBUG_NAMES
-      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG}-${Boost_LIB_VERSION}
+      ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG}${_boost_ARCHITECTURE_TAG}-${Boost_LIB_VERSION}
       ${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${COMPONENT}${_boost_MULTITHREADED}${_boost_DEBUG_STATIC_ABI_TAG} )
   endif()
   if(Boost_THREADAPI AND ${COMPONENT} STREQUAL "thread")
