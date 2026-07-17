$NetBSD: patch-cmake_dependencies.cmake,v 1.1 2026/07/17 16:42:13 wiz Exp $

cmake 4.4.0 compatibility
https://github.com/GNS3/dynamips/issues/312

--- cmake/dependencies.cmake.orig	2026-04-18 11:11:19.000000000 +0000
+++ cmake/dependencies.cmake
@@ -35,15 +35,15 @@ endif ( NOT CMAKE_COMPILER_IS_GNUCC AND NOT CMAKE_COMP
       )
 endif ( NOT CMAKE_COMPILER_IS_GNUCC AND NOT CMAKE_COMPILER_IS_CLANG AND NOT ANY_COMPILER )
 
-set ( DYNAMIPS_FLAGS -Wall -O2 -fomit-frame-pointer )
+set ( DYNAMIPS_FLAGS "-Wall -O2 -fomit-frame-pointer" )
 set ( DYNAMIPS_DEFINITIONS )
 set ( DYNAMIPS_INCLUDES )
 set ( DYNAMIPS_LIBRARIES ${CMAKE_DL_LIBS} )
 if ( CYGWIN )
-   list ( APPEND DYNAMIPS_FLAGS -static -static-libgcc )
+   string ( APPEND DYNAMIPS_FLAGS "-static -static-libgcc" )
 endif ( CYGWIN )
 macro ( set_cmake_required )
-   set ( CMAKE_REQUIRED_FLAGS       ${DYNAMIPS_FLAGS} )
+   set ( CMAKE_REQUIRED_FLAGS       "${DYNAMIPS_FLAGS}" )
    set ( CMAKE_REQUIRED_DEFINITIONS ${DYNAMIPS_DEFINITIONS} )
    set ( CMAKE_REQUIRED_INCLUDES    ${DYNAMIPS_INCLUDES} )
    set ( CMAKE_REQUIRED_LIBRARIES   ${DYNAMIPS_LIBRARIES} )
@@ -62,7 +62,7 @@ set_cmake_required ()
 #endif
 " )
 set_cmake_required ()
-list ( INSERT CMAKE_REQUIRED_FLAGS 0 -m64 )
+string (APPEND CMAKE_REQUIRED_FLAGS "0 -m64" )
 check_c_source_compiles ( "${_code}" ARCH_AMD64 )
 set ( _code "
 #if defined(__i386) || defined(__i386__) || defined(_M_IX86)
@@ -72,7 +72,7 @@ set_cmake_required ()
 #endif
 " )
 set_cmake_required ()
-list ( INSERT CMAKE_REQUIRED_FLAGS 0 -m32 )
+string (APPEND CMAKE_REQUIRED_FLAGS "0 -m32" )
 check_c_source_compiles ( "${_code}" ARCH_X86 )
 set ( _code "
 #if defined(__powerpc) || defined(__powerpc__) || defined(_M_PPC) || defined(_ARCH_PPC)
@@ -82,7 +82,7 @@ set_cmake_required ()
 #endif
 " )
 set_cmake_required ()
-list ( INSERT CMAKE_REQUIRED_FLAGS 0 -m32 )
+string (APPEND CMAKE_REQUIRED_FLAGS "0 -m32" )
 check_c_source_compiles ( "${_code}" ARCH_PPC32 )
 if ( ARCH_AMD64 )
    set ( _default "amd64" )
