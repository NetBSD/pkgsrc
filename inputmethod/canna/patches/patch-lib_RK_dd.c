$NetBSD: patch-lib_RK_dd.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

Fix "64 bit time_t on 32 bit architecture" problem.

--- lib/RK/dd.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ lib/RK/dd.c
@@ -39,6 +39,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#ifdef HAVE_TIME_T
+#define TIME_T time_t
+#else
+#define TIME_T long
+#endif
+
 #define	Calloc		calloc
 #define cx_gwt		cx_extdata.ptr
 #define	STRCMP(d, s)	strcmp((char *)(d), (char *)(s))
@@ -739,7 +745,7 @@ _RkRealizeDD(dd)
   int ret = -1;
   int tmpres;
   int			fdes;
-  long		tloc;
+  TIME_T		tloc;
 #ifdef __EMX__
   struct stat		statbuf;
 #endif
