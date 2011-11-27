$NetBSD: patch-.._spunk_machine.h,v 1.1 2011/11/27 19:36:09 joerg Exp $

--- ../spunk/machine.h.orig	2011-11-27 02:08:02.000000000 +0000
+++ ../spunk/machine.h
@@ -238,7 +238,7 @@ typedef unsigned        u32;            
 #    define CPU_LITTLE_ENDIAN
 #elif (BYTE_ORDER == BIG_ENDIAN)
 #    define CPU_BIG_ENDIAN
-#elif
+#else
 #    error Byte order not defined!
 #endif
 
