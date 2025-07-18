$NetBSD: patch-src_base_cl__low.h,v 1.2 2025/07/18 16:19:44 schmonz Exp $

--- src/base/cl_low.h.orig	2022-04-26 22:51:17.000000000 +0000
+++ src/base/cl_low.h
@@ -218,13 +218,7 @@ inline uint32 mulu32_unchecked (uint32 a
 #else
   extern "C" uint32 mulu32_ (uint32 arg1, uint32 arg2); // -> Low-Teil
 #endif
-#ifdef _MSC_VER
-  // Workaround MSVC compiler bug: extern "C" results in wrong symbols, when
-  // declared inside a namespace!
 } extern "C" uint32 mulu32_high; namespace cln {        // -> High-Teil
-#else
-  extern "C" uint32 mulu32_high;                        // -> High-Teil
-#endif
 #if defined(__GNUC__) && defined(__m68k__) && !defined(NO_ASM)
   #define mulu32(x,y,hi_zuweisung,lo_zuweisung)  \
     ({ var uint32 _x = (x);       \
@@ -537,12 +531,7 @@ inline uint32 mulu32_unchecked (uint32 a
 // < uint16 r: x mod y
 // < x = q*y+r
   extern "C" uint32 divu_3216_3216_ (uint32 x, uint16 y); // -> Quotient q
-#ifdef _MSC_VER
-  // Workaround MSVC compiler bug.
 } extern "C" uint16 divu_16_rest; namespace cln {         // -> Rest r
-#else
-  extern "C" uint16 divu_16_rest;                         // -> Rest r
-#endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
   #define divu_3216_3216(x,y,q_zuweisung,r_zuweisung)  \
     ({var uint32 __x = (x);        \
@@ -592,12 +581,7 @@ inline uint32 mulu32_unchecked (uint32 a
 // < uint32 r: x mod y
 // < x = q*y+r
   extern "C" uint32 divu_3232_3232_ (uint32 x, uint32 y); // -> Quotient q
-#ifdef _MSC_VER
-  // Workaround MSVC compiler bug.
 } extern "C" uint32 divu_32_rest; namespace cln {         // -> Rest r
-#else
-  extern "C" uint32 divu_32_rest;                         // -> Rest r
-#endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
   #define divu_3232_3232(x,y,q_zuweisung,r_zuweisung)  \
     ({var uint32 __x = (x);        \
