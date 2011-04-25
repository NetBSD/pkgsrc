$NetBSD: patch-include_my_handler.h,v 1.1.1.1 2011/04/25 21:12:53 adam Exp $

Adjust HA_MAX_KEY_LENGTH x4.

--- include/my_handler.h.orig	2010-02-04 11:37:06.000000000 +0000
+++ include/my_handler.h
@@ -41,7 +41,7 @@ extern "C" {
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and HA_MAX_KEY_LENGTH.
 */
 
-#define HA_MAX_KEY_LENGTH           1000        /* Max length in bytes */
+#define HA_MAX_KEY_LENGTH           4000        /* Max length in bytes */
 #define HA_MAX_KEY_SEG              16          /* Max segments for key */
 
 #define HA_MAX_POSSIBLE_KEY_BUFF    (HA_MAX_KEY_LENGTH + 24+ 6+6)
