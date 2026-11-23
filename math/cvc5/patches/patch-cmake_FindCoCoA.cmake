$NetBSD: patch-cmake_FindCoCoA.cmake,v 1.1 2026/11/23 07:51:44 wiz Exp $

Fix build with cmake 4.5.
https://github.com/cvc5/cvc5/commit/afabed488b81710676fa81df408989d550779988

--- cmake/FindCoCoA.cmake.orig	2026-11-23 07:47:53.743879575 +0000
+++ cmake/FindCoCoA.cmake
@@ -33,7 +33,6 @@ if(CoCoA_INCLUDE_DIR AND CoCoA_LIBRARIES)
   try_compile(CoCoA_USABLE "${DEPS_BASE}/try_compile/CoCoA-EP"
     "${CMAKE_CURRENT_LIST_DIR}/deps-utils/cocoa-test.cpp"
     CMAKE_FLAGS
-      "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
       "-DINCLUDE_DIRECTORIES=${CoCoA_INCLUDE_DIR}"
     LINK_LIBRARIES ${CoCoA_LIBRARIES} ${GMP_LIBRARIES} ${GMPXX_LIBRARIES}
   )
