$NetBSD: patch-libelftc___libelftc.h,v 1.1 2017/05/31 22:14:43 agc Exp $

avoid error - cast float value to size_t before using it

--- libelftc/_libelftc.h	2017/05/31 22:09:00	1.1
+++ libelftc/_libelftc.h	2017/05/31 22:09:18
@@ -55,7 +55,7 @@
 	char		**container;
 };
 
-#define BUFFER_GROWFACTOR	1.618
+#define BUFFER_GROWFACTOR	(size_t)1.618
 #define VECTOR_DEF_CAPACITY	8
 #define	ELFTC_ISDIGIT(C) 	(isdigit((C) & 0xFF))
 
