$NetBSD: patch-src_h-type.h,v 1.1 2020/01/24 13:33:33 pho Exp $

Use the correct int types. The original code doesn't work on 64-bits
machines.

--- src/h-type.h.orig	2017-04-30 13:03:32.000000000 +0000
+++ src/h-type.h
@@ -3,6 +3,8 @@
 #ifndef INCLUDED_H_TYPE_H
 #define INCLUDED_H_TYPE_H
 
+#include <stdint.h>
+
 /*
  * Basic "types".
  *
@@ -91,7 +93,7 @@ typedef int errr;
 
 /* Note that unsigned values can cause math problems */
 /* An unsigned byte of memory */
-typedef unsigned char byte;
+typedef uint8_t byte;
 
 /* Note that a bool is smaller than a full "int" */
 /* Simple True/False type */
@@ -113,17 +115,12 @@ typedef unsigned long huge;
 
 
 /* Signed/Unsigned 16 bit value */
-typedef signed short s16b;
-typedef unsigned short u16b;
+typedef int16_t s16b;
+typedef uint16_t u16b;
 
 /* Signed/Unsigned 32 bit value */
-#ifdef L64	/* 64 bit longs */
-typedef signed int s32b;
-typedef unsigned int u32b;
-#else
-typedef signed long s32b;
-typedef unsigned long u32b;
-#endif
+typedef int32_t s32b;
+typedef uint32_t u32b;
 
 
 
