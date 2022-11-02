$NetBSD: patch-include_my__compare.h,v 1.2 2022/11/02 17:02:10 jperkin Exp $

Adjust HA_MAX_KEY_LENGTH x4.
XXX: why? there's no documentation at all for this or commit history

--- include/my_compare.h.orig	2019-12-09 19:53:17.000000000 +0000
+++ include/my_compare.h
@@ -49,7 +49,7 @@
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and HA_MAX_KEY_LENGTH.
 */
 
-#define HA_MAX_KEY_LENGTH 1000 /* Max length in bytes */
+#define HA_MAX_KEY_LENGTH 4000 /* Max length in bytes */
 #define HA_MAX_KEY_SEG 16      /* Max segments for key */
 
 #define HA_MAX_POSSIBLE_KEY_BUFF (HA_MAX_KEY_LENGTH + 24 + 6 + 6)
