$NetBSD: patch-include_vlc__atomic.h,v 1.1 2015/09/23 12:02:27 joerg Exp $

--- include/vlc_atomic.h.orig	2015-09-21 14:00:58.000000000 +0000
+++ include/vlc_atomic.h
@@ -25,13 +25,26 @@
  * \file
  * Atomic operations do not require locking, but they are not very powerful.
  */
+#if (__STDC_VERSION__ >= 201112L) && !defined (__STDC_NO_ATOMICS__)
+#define HAS_STDATOMIC_H
+#elif __cplusplus - 0 >= 201103L
+#define HAS_ATOMIC
+#elif defined(__has_include)
+#  if defined(__cplusplus) && __has_include(<atomic>)
+#  define HAS_ATOMIC
+#  elif __has_include(<stdatomic.h>)
+#  define HAS_STDATOMIC_H
+#  endif
+#endif
 
-# if !defined (__cplusplus) && (__STDC_VERSION__ >= 201112L) \
-  && !defined (__STDC_NO_ATOMICS__)
 
+# if defined(HAS_STDATOMIC_H)
 /*** Native C11 atomics ***/
 #  include <stdatomic.h>
-
+# elif defined(HAS_ATOMIC)
+#  include <atomic>
+using std::atomic_uint_least32_t;
+using std::atomic_uintptr_t;
 # else
 
 #  define ATOMIC_FLAG_INIT false
@@ -310,7 +323,7 @@ typedef         uintmax_t atomic_uintmax
 /**
  * Memory storage space for an atom. Never access it directly.
  */
-typedef union
+typedef struct
 {
     atomic_uintptr_t u;
 } vlc_atomic_t;
