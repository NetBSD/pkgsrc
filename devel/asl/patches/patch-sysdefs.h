$NetBSD: patch-sysdefs.h,v 1.1 2026/08/23 20:34:39 he Exp $

Provide portability to the NetBSD PowerPC ports.

--- sysdefs.h.orig	2026-08-23 20:15:04.141222279 +0000
+++ sysdefs.h
@@ -138,7 +138,7 @@ typedef unsigned int as_uint32_t;
 /*---------------------------------------------------------------------------*/
 /* ditto for PPC platforms */
 
-#ifdef __PPC
+#if defined(__PPC) || defined(_ARCH_PPC)
 # ifndef _POWER
 #  define _POWER
 # endif
@@ -674,6 +674,30 @@ typedef unsigned int as_uint32_t;
 #endif
 
 /*---------------------------------------------------------------------------*/
+/* POWER with NetBSD */
+
+#ifdef __NetBSD__
+#define ARCHSYSNAME "NetBSD-ppc"
+#define DEFSMADE
+#define OPENRDMODE "r" 
+#define OPENWRMODE "w"
+#define OPENUPMODE "r+"
+#define IEEEFLOAT_8_DOUBLE
+typedef signed char as_int8_t;
+typedef unsigned char as_uint8_t;
+typedef signed short as_int16_t;
+typedef unsigned short as_uint16_t;
+#define HAS16
+typedef signed int as_int32_t;
+#define PRIas_int32_t "d"
+typedef unsigned int as_uint32_t;
+#undef AS_HAS_LONGLONG
+#define AS_HAS_LONGLONG 1
+#define AS_64_IS_LONGLONG 1
+#define LOCALE_NLS
+#endif
+
+/*---------------------------------------------------------------------------*/
 /* POWER with Linux (Macintosh) */
 
 #ifdef __linux__
