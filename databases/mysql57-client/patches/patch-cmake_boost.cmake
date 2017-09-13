$NetBSD: patch-cmake_boost.cmake,v 1.6 2017/09/13 17:34:41 adam Exp $

Fix to use a newer version of Boost.

--- cmake/boost.cmake.orig	2017-06-22 14:13:19.000000000 +0000
+++ cmake/boost.cmake
@@ -13,7 +13,7 @@
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
-# We want boost 1.59.0 in order to build our boost/geometry code.
+# We want boost 1.65.1 in order to build our boost/geometry code.
 # The boost tarball is fairly big, and takes several minutes
 # to download. So we recommend downloading/unpacking it
 # only once, in a place visible from any bzr sandbox.
@@ -31,10 +31,10 @@
 # we assume that the correct version (see below)
 # is installed on the compile host in the standard location.
 
-SET(BOOST_PACKAGE_NAME "boost_1_59_0")
+SET(BOOST_PACKAGE_NAME "boost_1_65_1")
 SET(BOOST_TARBALL "${BOOST_PACKAGE_NAME}.tar.gz")
 SET(BOOST_DOWNLOAD_URL
-  "http://sourceforge.net/projects/boost/files/boost/1.59.0/${BOOST_TARBALL}"
+  "http://sourceforge.net/projects/boost/files/boost/1.65.1/${BOOST_TARBALL}"
   )
 
 SET(OLD_PACKAGE_NAMES "boost_1_55_0 boost_1_56_0 boost_1_57_0 boost_1_58_0")
@@ -244,7 +244,7 @@ ENDIF()
 # //  BOOST_VERSION % 100 is the patch level
 # //  BOOST_VERSION / 100 % 1000 is the minor version
 # //  BOOST_VERSION / 100000 is the major version
-# #define BOOST_VERSION 105900
+# #define BOOST_VERSION 106501
 FILE(STRINGS "${BOOST_INCLUDE_DIR}/boost/version.hpp"
   BOOST_VERSION_NUMBER
   REGEX "^#define[\t ]+BOOST_VERSION[\t ][0-9]+.*"
@@ -262,9 +262,9 @@ IF(NOT BOOST_MAJOR_VERSION EQUAL 10)
   COULD_NOT_FIND_BOOST()
 ENDIF()
 
-IF(NOT BOOST_MINOR_VERSION EQUAL 59)
+IF(NOT BOOST_MINOR_VERSION EQUAL 65)
   MESSAGE(WARNING "Boost minor version found is ${BOOST_MINOR_VERSION} "
-    "we need 59"
+    "we need 65"
     )
   COULD_NOT_FIND_BOOST()
 ENDIF()
@@ -272,10 +272,10 @@ ENDIF()
 MESSAGE(STATUS "BOOST_INCLUDE_DIR ${BOOST_INCLUDE_DIR}")
 
 # We have a limited set of patches/bugfixes here:
-SET(BOOST_PATCHES_DIR "${CMAKE_SOURCE_DIR}/include/boost_1_59_0/patches")
+SET(BOOST_PATCHES_DIR "${CMAKE_SOURCE_DIR}/include/boost_1_65_1/patches")
 
 # We have a limited set of source files here:
-SET(BOOST_SOURCES_DIR "${CMAKE_SOURCE_DIR}/include/boost_1_59_0")
+SET(BOOST_SOURCES_DIR "${CMAKE_SOURCE_DIR}/include/boost_1_65_1")
 
 # Bug in sqrt(NaN) on 32bit platforms
 IF(SIZEOF_VOIDP EQUAL 4)
