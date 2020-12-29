--- gpsd.h-orig	Tue Dec 29 05:25:00 2020
+++ gpsd.h	Tue Dec 29 05:25:50 2020
@@ -1077,7 +1077,7 @@
 #define NAN (0.0f/0.0f)
 #endif

-#if !defined(HAVE_CFMAKERAW)
+#if !defined(HAVE_CFMAKERAW) || defined(__sun)
 /*
  * POSIX does not specify cfmakeraw, but it is pretty common.  We
  * provide an implementation in serial.c for systems that lack it.
