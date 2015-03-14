$NetBSD: patch-dnstracer.c,v 1.2 2015/03/14 14:33:37 tnn Exp $
There is no gethostbyname2 on SunOS, always use the wrapper

--- dnstracer.c.orig	2008-06-11 12:50:53.000000000 +0000
+++ dnstracer.c
@@ -66,7 +66,7 @@
 #define DEFAULT_NOIPV6			0
 #define DEFAULT_EDNS0SIZE		1500
 
-#ifdef NOIPV6
+#if defined(NOIPV6) || defined(__sun)
 #define gethostbyname2(a, b) gethostbyname(a)
 #endif
 
