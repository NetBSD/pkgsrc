$NetBSD: patch-include_myisam.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Adjust MI_MAX_KEY_LENGTH x4.

--- include/myisam.h.orig	2015-02-13 12:07:01.000000000 +0000
+++ include/myisam.h
@@ -44,7 +44,7 @@ extern "C" {
   The following defines can be increased if necessary.
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and MI_MAX_KEY_LENGTH.
 */
-#define MI_MAX_KEY_LENGTH           1000            /* Max length in bytes */
+#define MI_MAX_KEY_LENGTH           4000            /* Max length in bytes */
 #define MI_MAX_KEY_SEG              16              /* Max segments for key */
 
 #define MI_NAME_IEXT	".MYI"
