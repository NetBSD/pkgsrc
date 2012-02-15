$NetBSD: patch-libvisual_lv__types.h,v 1.1 2012/02/15 22:01:43 hans Exp $

--- libvisual/lv_types.h.orig	2005-01-01 15:11:56.000000000 +0100
+++ libvisual/lv_types.h	2012-01-11 15:00:23.565973572 +0100
@@ -32,18 +32,6 @@ extern "C" {
 
 #define VISUAL_CHECK_CAST(uiobj, cast_type, cast)    ((cast*) (uiobj))
 
-#ifndef uint8_t
-#define uint8_t		u_int8_t
-#endif
-	
-#ifndef uint16_t
-#define uint16_t	u_int16_t
-#endif
-
-#ifndef uint32_t
-#define uint32_t	u_int32_t
-#endif
-
 #ifdef __cplusplus
 }
 #endif /* __cplusplus */
