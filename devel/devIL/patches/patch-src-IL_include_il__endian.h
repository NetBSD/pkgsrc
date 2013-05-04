$NetBSD: patch-src-IL_include_il__endian.h,v 1.1 2013/05/04 12:43:00 joerg Exp $

--- src-IL/include/il_endian.h.orig	2013-05-03 17:18:05.000000000 +0000
+++ src-IL/include/il_endian.h
@@ -39,8 +39,9 @@
 	#define BigDouble(d)  
 #else
 	#undef __BIG_ENDIAN__
-	#undef __LITTLE_ENDIAN__  // Not sure if it's defined by any compiler...
-	#define __LITTLE_ENDIAN__
+#ifndef __LITTLE_ENDIAN__ 
+#define __LITTLE_ENDIAN__
+#endif
 	#define Short(s)  
 	#define UShort(s)  
 	#define Int(i)  
