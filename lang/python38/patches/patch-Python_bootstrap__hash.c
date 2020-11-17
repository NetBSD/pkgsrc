$NetBSD: patch-Python_bootstrap__hash.c,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Python/bootstrap_hash.c.orig	2020-09-23 12:36:32.000000000 +0000
+++ Python/bootstrap_hash.c
@@ -25,6 +25,16 @@
 #  include <sanitizer/msan_interface.h>
 #endif
 
+#if defined(__APPLE__) && defined(__has_builtin)
+#  if __has_builtin(__builtin_available)
+#    define HAVE_GETENTRYPY_GETRANDOM_RUNTIME __builtin_available(macOS 10.12, iOS 10.10, tvOS 10.0, watchOS 3.0, *)
+#  endif
+#endif
+#ifndef HAVE_GETENTRYPY_GETRANDOM_RUNTIME
+#  define HAVE_GETENTRYPY_GETRANDOM_RUNTIME 1
+#endif
+
+
 #ifdef Py_DEBUG
 int _Py_HashSecret_Initialized = 0;
 #else
@@ -208,6 +218,16 @@ py_getrandom(void *buffer, Py_ssize_t si
      error.
 
    getentropy() is retried if it failed with EINTR: interrupted by a signal. */
+
+#if defined(__APPLE__) && defined(__has_attribute) && __has_attribute(availability)
+static int
+py_getentropy(char *buffer, Py_ssize_t size, int raise)
+        __attribute__((availability(macos,introduced=10.12)))
+        __attribute__((availability(ios,introduced=10.0)))
+        __attribute__((availability(tvos,introduced=10.0)))
+        __attribute__((availability(watchos,introduced=3.0)));
+#endif
+
 static int
 py_getentropy(char *buffer, Py_ssize_t size, int raise)
 {
@@ -498,19 +518,21 @@ pyurandom(void *buffer, Py_ssize_t size,
 #else
 
 #if defined(PY_GETRANDOM) || defined(PY_GETENTROPY)
+    if (HAVE_GETENTRYPY_GETRANDOM_RUNTIME) {
 #ifdef PY_GETRANDOM
-    res = py_getrandom(buffer, size, blocking, raise);
+        res = py_getrandom(buffer, size, blocking, raise);
 #else
-    res = py_getentropy(buffer, size, raise);
+        res = py_getentropy(buffer, size, raise);
 #endif
-    if (res < 0) {
-        return -1;
-    }
-    if (res == 1) {
-        return 0;
-    }
-    /* getrandom() or getentropy() function is not available: failed with
-       ENOSYS or EPERM. Fall back on reading from /dev/urandom. */
+        if (res < 0) {
+            return -1;
+        }
+        if (res == 1) {
+            return 0;
+        }
+        /* getrandom() or getentropy() function is not available: failed with
+           ENOSYS or EPERM. Fall back on reading from /dev/urandom. */
+    } /* end of availability block */
 #endif
 
     return dev_urandom(buffer, size, raise);
