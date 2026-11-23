$NetBSD: patch-cmake_FindGMP.cmake,v 1.1 2026/11/23 07:51:44 wiz Exp $

Fix build with cmake 4.5.
https://github.com/cvc5/cvc5/commit/afabed488b81710676fa81df408989d550779988

--- cmake/FindGMP.cmake.orig	2026-11-23 07:48:07.327143012 +0000
+++ cmake/FindGMP.cmake
@@ -51,7 +51,6 @@ if(GMP_INCLUDE_DIR AND GMPXX_INCLUDE_DIR AND GMP_LIBRA
   try_compile(GMP_USABLE "${DEPS_BASE}/try_compile/GMP-EP"
     "${CMAKE_CURRENT_LIST_DIR}/deps-utils/gmp-test.cpp"
     CMAKE_FLAGS
-      "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
       "-DINCLUDE_DIRECTORIES=${GMP_INCLUDE_DIR}"
     LINK_LIBRARIES ${GMP_LIBRARIES} ${GMPXX_LIBRARIES}
   )
