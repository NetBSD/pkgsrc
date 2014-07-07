$NetBSD: patch-main.c,v 1.1 2014/07/07 18:06:58 jperkin Exp $

Include limits.h for INT_{MIN,MAX}

--- main.c.orig	2011-01-02 22:57:56.000000000 +0000
+++ main.c
@@ -15,6 +15,7 @@
 #endif	/* NO_MACRO */
 
 #include <err.h>
+#include <limits.h>
 
 int		 thisflag;			/* flags, this command	*/
 int		 lastflag;			/* flags, last command	*/
