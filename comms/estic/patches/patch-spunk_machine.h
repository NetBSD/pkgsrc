$NetBSD: patch-spunk_machine.h,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/machine.h.orig	1997-02-18 14:41:50.000000000 +0000
+++ spunk/machine.h
@@ -238,7 +238,7 @@ typedef unsigned        u32;            
 #    define CPU_LITTLE_ENDIAN
 #elif (BYTE_ORDER == BIG_ENDIAN)
 #    define CPU_BIG_ENDIAN
-#elif
+#else
 #    error Byte order not defined!
 #endif
 
@@ -312,7 +312,7 @@ typedef unsigned        u32;            
 
 #ifdef SOLARIS
 
-#include <sys/endian.h>
+#include <sys/byteorder.h>
 #ifdef _BIG_ENDIAN
 #    define CPU_BIG_ENDIAN
 #else
