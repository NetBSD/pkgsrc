$NetBSD: patch-cmake_pkg-config.cmake,v 1.1 2023/05/23 21:01:12 adam Exp $

Detect pkg-config on other systems.

--- cmake/pkg-config.cmake.orig	2023-05-23 14:53:30.967918710 +0000
+++ cmake/pkg-config.cmake
@@ -21,7 +21,7 @@
 # Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 
 MACRO(MYSQL_CHECK_PKGCONFIG)
-  IF(LINUX OR FREEBSD)
+  IF(UNIX)
     # Do a sanity check, before bailing out in FIND_PACKAGE below.
     FIND_PROGRAM(MY_PKG_CONFIG_EXECUTABLE NAMES pkg-config
       DOC "pkg-config executable")
