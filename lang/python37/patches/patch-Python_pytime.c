$NetBSD: patch-Python_pytime.c,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Python/pytime.c.orig	2020-08-15 05:20:16.000000000 +0000
+++ Python/pytime.c
@@ -5,6 +5,12 @@
 
 #if defined(__APPLE__)
 #include <mach/mach_time.h>   /* mach_absolute_time(), mach_timebase_info() */
+
+#if defined(__APPLE__) && defined(__has_builtin)
+#  if __has_builtin(__builtin_available)
+#    define HAVE_CLOCK_GETTIME_RUNTIME __builtin_available(macOS 10.12, iOS 10.0, tvOS 10.0, watchOS 3.0, *)
+#  endif
+#endif
 #endif
 
 #define _PyTime_check_mul_overflow(a, b) \
@@ -683,15 +689,22 @@ pygettimeofday(_PyTime_t *tp, _Py_clock_
 
 #else   /* MS_WINDOWS */
     int err;
-#ifdef HAVE_CLOCK_GETTIME
+#if defined(HAVE_CLOCK_GETTIME)
     struct timespec ts;
-#else
+#endif
+
+#if !defined(HAVE_CLOCK_GETTIME) || defined(__APPLE__)
     struct timeval tv;
 #endif
 
     assert(info == NULL || raise);
 
 #ifdef HAVE_CLOCK_GETTIME
+
+#ifdef HAVE_CLOCK_GETTIME_RUNTIME
+    if (HAVE_CLOCK_GETTIME_RUNTIME) {
+#endif
+
     err = clock_gettime(CLOCK_REALTIME, &ts);
     if (err) {
         if (raise) {
@@ -715,7 +728,14 @@ pygettimeofday(_PyTime_t *tp, _Py_clock_
             info->resolution = 1e-9;
         }
     }
-#else   /* HAVE_CLOCK_GETTIME */
+
+#ifdef HAVE_CLOCK_GETTIME_RUNTIME
+    } else {
+#endif
+
+#endif
+
+#if !defined(HAVE_CLOCK_GETTIME) || defined(HAVE_CLOCK_GETTIME_RUNTIME)
 
      /* test gettimeofday() */
 #ifdef GETTIMEOFDAY_NO_TZ
@@ -739,6 +759,11 @@ pygettimeofday(_PyTime_t *tp, _Py_clock_
         info->monotonic = 0;
         info->adjustable = 1;
     }
+
+#if defined(HAVE_CLOCK_GETTIME_RUNTIME) && defined(HAVE_CLOCK_GETTIME)
+    } /* end of availibity block */
+#endif
+
 #endif   /* !HAVE_CLOCK_GETTIME */
 #endif   /* !MS_WINDOWS */
     return 0;
