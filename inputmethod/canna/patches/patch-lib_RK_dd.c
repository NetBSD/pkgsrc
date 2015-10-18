$NetBSD: patch-lib_RK_dd.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Fix "64 bit time_t on 32 bit architecture" problem.

--- lib/RK/dd.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ lib/RK/dd.c
@@ -42,6 +42,12 @@ static char rcsid[]="$Id: dd.c,v 1.5 200
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
@@ -742,7 +748,7 @@ _RkRealizeDD(dd)
   int ret = -1;
   int tmpres;
   int			fdes;
-  long		tloc;
+  TIME_T		tloc;
 #ifdef __EMX__
   struct stat		statbuf;
 #endif
