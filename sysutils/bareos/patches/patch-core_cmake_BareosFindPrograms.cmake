$NetBSD: patch-core_cmake_BareosFindPrograms.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	the pkgsrc build system provides awk on the path.
	the cmake build system uses this build path for
	installed scripts - change the way the awk path
	is found.

--- core/cmake/BareosFindPrograms.cmake.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/cmake/BareosFindPrograms.cmake
@@ -18,10 +18,14 @@
 #   02110-1301, USA.
 
 # find programs
+if(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+  # avoid confusion with pkgsrc build time tool path
+  find_program(AWK awk PATHS /bin /usr/bin ENV TOOLS_PLATFORM.awk NO_DEFAULT_PATH )
+endif()
 find_program(AWK awk)
 find_program(GAWK gawk)
 if(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-  set(AWK ${GAWK})
+ set(AWK ${GAWK})
 endif()
 
 find_program(PIDOF pidof)
