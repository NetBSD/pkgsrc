$NetBSD: patch-llong.h,v 1.1 2012/08/10 14:59:58 is Exp $

--- llong.h.orig        2010-10-03 16:00:42.000000000 +0000
+++ llong.h
@@ -25,7 +25,7 @@
 /* if off_t is already 64 bits, be happy, and don't worry about the
  * loff_t and llseek stuff */
 #define MT_OFF_T off_t
-#define MT_SIZE_T size_t
+#define MT_SIZE_T off_t
 #endif

 #ifndef MT_OFF_T
