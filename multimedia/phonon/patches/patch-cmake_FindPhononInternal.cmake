$NetBSD: patch-cmake_FindPhononInternal.cmake,v 1.4 2016/04/26 08:08:50 markd Exp $

Disable Darwin section, creates unusable libraries.

--- cmake/FindPhononInternal.cmake.orig	2016-04-18 04:25:17.000000000 +0000
+++ cmake/FindPhononInternal.cmake
@@ -92,14 +92,14 @@ set(INSTALL_TARGETS_DEFAULT_ARGS RUNTIME
                                  ARCHIVE DESTINATION "${LIB_INSTALL_DIR}" COMPONENT Devel)
 
 # on the Mac support an extra install directory for application bundles
-if(APPLE)
+if(notAPPLE)
     set(INSTALL_TARGETS_DEFAULT_ARGS ${INSTALL_TARGETS_DEFAULT_ARGS}
                                      BUNDLE DESTINATION "${BUNDLE_INSTALL_DIR}")
     set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS   "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS}   -flat_namespace -undefined dynamic_lookup")
     set(CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS "${CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS} -flat_namespace -undefined dynamic_lookup")
 
    set(CMAKE_INSTALL_NAME_DIR ${LIB_INSTALL_DIR})
-endif(APPLE)
+endif(notAPPLE)
 
 if (NOT PHONON_BUILD_PHONON4QT5) # Qt4
     include(${phonon_cmake_module_dir}/PhononQt4.cmake)
