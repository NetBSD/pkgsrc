$NetBSD: patch-cmake_OpenCVDetectPython.cmake,v 1.2 2024/02/09 11:50:30 adam Exp $

numpy.distutils is removed in numpy 1.26 on Python 3.12
https://github.com/opencv/opencv/pull/24351

Do not look for Python 2.x.

--- cmake/OpenCVDetectPython.cmake.orig	2023-06-27 11:29:13.000000000 +0000
+++ cmake/OpenCVDetectPython.cmake
@@ -216,7 +216,7 @@ if(NOT ${found})
           message(STATUS "  PYTHON3_NUMPY_INCLUDE_DIRS")
         else()
           # Attempt to discover the NumPy include directory. If this succeeds, then build python API with NumPy
-          execute_process(COMMAND "${_executable}" -c "import os; os.environ['DISTUTILS_USE_SDK']='1'; import numpy.distutils; print(os.pathsep.join(numpy.distutils.misc_util.get_numpy_include_dirs()))"
+          execute_process(COMMAND "${_executable}" -c "import numpy; print(numpy.get_include())"
                           RESULT_VARIABLE _numpy_process
                           OUTPUT_VARIABLE _numpy_include_dirs
                           OUTPUT_STRIP_TRAILING_WHITESPACE)
@@ -268,13 +268,6 @@ if(OPENCV_PYTHON_SKIP_DETECTION)
   return()
 endif()
 
-find_python("" "${MIN_VER_PYTHON2}" PYTHON2_LIBRARY PYTHON2_INCLUDE_DIR
-    PYTHON2INTERP_FOUND PYTHON2_EXECUTABLE PYTHON2_VERSION_STRING
-    PYTHON2_VERSION_MAJOR PYTHON2_VERSION_MINOR PYTHON2LIBS_FOUND
-    PYTHON2LIBS_VERSION_STRING PYTHON2_LIBRARIES PYTHON2_LIBRARY
-    PYTHON2_DEBUG_LIBRARIES PYTHON2_LIBRARY_DEBUG PYTHON2_INCLUDE_PATH
-    PYTHON2_INCLUDE_DIR PYTHON2_INCLUDE_DIR2 PYTHON2_PACKAGES_PATH
-    PYTHON2_NUMPY_INCLUDE_DIRS PYTHON2_NUMPY_VERSION)
 
 option(OPENCV_PYTHON3_VERSION "Python3 version" "")
 find_python("${OPENCV_PYTHON3_VERSION}" "${MIN_VER_PYTHON3}" PYTHON3_LIBRARY PYTHON3_INCLUDE_DIR
