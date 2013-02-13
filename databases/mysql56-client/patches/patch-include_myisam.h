$NetBSD: patch-include_myisam.h,v 1.1 2013/02/13 21:00:05 adam Exp $

Adjust MI_MAX_KEY_LENGTH x4.

--- include/myisam.h.orig	2010-02-04 11:37:06.000000000 +0000
+++ include/myisam.h
@@ -49,7 +49,7 @@ extern "C" {
   The following defines can be increased if necessary.
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and MI_MAX_KEY_LENGTH.
 */
-#define MI_MAX_KEY_LENGTH           1000            /* Max length in bytes */
+#define MI_MAX_KEY_LENGTH           4000            /* Max length in bytes */
 #define MI_MAX_KEY_SEG              16              /* Max segments for key */
 
 #define MI_MAX_KEY_BUFF  (MI_MAX_KEY_LENGTH+MI_MAX_KEY_SEG*6+8+8)
