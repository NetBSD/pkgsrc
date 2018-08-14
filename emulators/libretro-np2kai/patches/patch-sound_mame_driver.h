$NetBSD: patch-sound_mame_driver.h,v 1.1 2018/08/14 16:44:08 nia Exp $

Use the standard keyword for making a function inline.

--- sound/mame/driver.h.orig	2018-07-12 22:06:17.000000000 +0000
+++ sound/mame/driver.h
@@ -8,17 +8,7 @@
 #define HAS_Y8950  1
 #define HAS_YMF262 1
 
-#if defined(_MSC_VER)
-#pragma warning(disable: 4244)
-#pragma warning(disable: 4245)
-#define INLINE __inline
-#elif defined(__BORLANDC__)
-#define INLINE __inline
-#elif defined(__GNUC__)
-#define INLINE __inline__ __attribute__((always_inline))
-#else
-#define INLINE
-#endif
+#define INLINE inline
 
 #define logerror(x,y,z)
 //typedef signed int stream_sample_t;
