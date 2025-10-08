$NetBSD: patch-src_typedef.h,v 1.1 2025/10/08 09:19:14 tsutsui Exp $

- fix endian issue on Z80 emulation on big endian ARM
 https://github.com/eighttails/PC6001VX/issues/25

--- src/typedef.h.orig	2025-10-08 08:54:41.470982282 +0000
+++ src/typedef.h
@@ -77,7 +77,8 @@ using P6VPATH = std::string;
 #define P6V_BIG_ENDIAN	4321
 
 #ifndef BYTEORDER
-#if defined(__hppa__) || \
+#if defined(__ARMEB__) || \
+    defined(__hppa__) || \
     defined(__m68k__) || defined(mc68000) || defined(_M_M68K) || \
     (defined(__MIPS__) && defined(__MISPEB__)) || \
     defined(__ppc__) || defined(__POWERPC__) || defined(_M_PPC) || \
