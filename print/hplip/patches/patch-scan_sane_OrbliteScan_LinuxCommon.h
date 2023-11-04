$NetBSD: patch-scan_sane_OrbliteScan_LinuxCommon.h,v 1.2 2023/11/04 14:22:16 wiz Exp $

--- scan/sane/OrbliteScan/LinuxCommon.h.orig	2019-12-10 05:00:30.000000000 +0000
+++ scan/sane/OrbliteScan/LinuxCommon.h
@@ -2,6 +2,7 @@
 #define H_LinuxCommon
 
 #include <sys/types.h>
+#include <stdint.h>
 
 /* Common typedefs for Linux */
 
@@ -9,19 +10,15 @@ typedef unsigned char *			StringPtr;
 typedef unsigned char			Boolean;
 typedef char *				Ptr;
 
-typedef unsigned char			UInt8;
+typedef uint8_t				UInt8;
 typedef UInt8*				PUInt8;
-typedef signed char			SInt8;
-typedef unsigned short			UInt16;
-typedef signed short			SInt16;
-typedef u_int32_t			UInt32;
+typedef int8_t				SInt8;
+typedef uint16_t			UInt16;
+typedef int16_t				SInt16;
+typedef uint32_t			UInt32;
 typedef int32_t				SInt32;
-//typedef unsigned long			UInt32;
-//typedef signed long			SInt32;
-typedef __S64_TYPE			SInt64;
-typedef __U64_TYPE			UInt64;
-typedef __S64_TYPE			int64_t;
-typedef __U64_TYPE			uint64_t;
+typedef int64_t				SInt64;
+typedef uint64_t			UInt64;
 
 //typedef unsigned long	ULONG;
 //typedef void*			LPVOID;
