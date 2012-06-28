$NetBSD: patch-libvisual_lv__types.h,v 1.2 2012/06/28 08:05:27 sbd Exp $

--- libvisual/lv_types.h.orig	2005-01-01 14:11:56.000000000 +0000
+++ libvisual/lv_types.h
@@ -32,6 +32,7 @@ extern "C" {
 
 #define VISUAL_CHECK_CAST(uiobj, cast_type, cast)    ((cast*) (uiobj))
 
+#ifndef __SunOS
 #ifndef uint8_t
 #define uint8_t		u_int8_t
 #endif
@@ -43,6 +44,7 @@ extern "C" {
 #ifndef uint32_t
 #define uint32_t	u_int32_t
 #endif
+#endif
 
 #ifdef __cplusplus
 }
