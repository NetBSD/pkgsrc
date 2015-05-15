$NetBSD: patch-src_base_cl__low.h,v 1.1 2015/05/15 09:17:03 joerg Exp $

--- src/base/cl_low.h.orig	2015-04-30 23:51:42.000000000 +0000
+++ src/base/cl_low.h
@@ -202,13 +202,7 @@ inline uint32 mulu32_unchecked (uint32 a
 // > arg1, arg2 : zwei 32-Bit-Zahlen
 // < 2^32*hi+lo : eine 64-Bit-Zahl
   extern "C" uint32 mulu32_ (uint32 arg1, uint32 arg2); // -> Low-Teil
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
@@ -530,12 +524,7 @@ inline uint32 mulu32_unchecked (uint32 a
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
@@ -585,12 +574,7 @@ inline uint32 mulu32_unchecked (uint32 a
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
