$NetBSD: patch-sc.h,v 1.1 2015/01/09 14:30:22 joerg Exp $

--- sc.h.orig	2015-01-09 12:50:27.000000000 +0000
+++ sc.h
@@ -418,9 +418,4 @@ extern	int collimit;
 
 #endif
 
-#if defined(BSD42) || defined(BSD43) && !defined(ultrix)
-#define	memcpy(dest, source, len)	bcopy(source, dest, (unsigned int)len);
-#define	memset(dest, zero, len)		bzero((dest), (unsigned int)(len));
-#else
-#include <memory.h>
-#endif
+#include <string.h>
