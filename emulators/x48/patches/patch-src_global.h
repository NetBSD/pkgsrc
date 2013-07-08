$NetBSD: patch-src_global.h,v 1.1 2013/07/08 08:37:10 he Exp $

Define CSRG_BASED if BSD is defined in the "non-linux" && non-Sun
branch.

--- src/global.h.orig	2011-11-15 03:03:40.000000000 +0000
+++ src/global.h
@@ -101,9 +101,13 @@
 
 #else  /* Not HP-UX */
 
+#if defined(BSD)
+#define CSRG_BASED	1
+#else
 #ifndef SUNOS
 #define SUNOS	1
 #endif
+#endif /* not BSD */
 
 #endif  /* Not HP-UX */
 #endif  /* Not Solaris */
