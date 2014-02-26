$NetBSD: patch-dnstracer.c,v 1.1 2014/02/26 18:17:39 wiedi Exp $
There is no gethostbyname2 on SunOS, always use the wrapper

--- dnstracer.c.orig	2008-02-09 12:47:37.000000000 +0000
+++ dnstracer.c
@@ -66,7 +66,7 @@
 #define DEFAULT_QUERYTYPE	ns_t_a
 #define DEFAULT_NOIPV6	0
 
-#ifdef NOIPV6
+#if defined(NOIPV6) || defined(__sun)
 #define gethostbyname2(a, b) gethostbyname(a)
 #endif
 
