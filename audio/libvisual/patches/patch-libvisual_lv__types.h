$NetBSD: patch-libvisual_lv__types.h,v 1.1 2012/02/15 21:58:44 hans Exp $

--- libvisual/lv_types.h.orig	2006-02-13 21:54:08.000000000 +0100
+++ libvisual/lv_types.h	2012-01-11 14:44:09.647013746 +0100
@@ -38,20 +38,6 @@ VISUAL_BEGIN_DECLS
 
 #define VISUAL_TABLESIZE(table)			(sizeof (table) / sizeof (table[0]))
 
-#if !defined(VISUAL_OS_WIN32)
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
-#endif /* !VISUAL_OS_WIN32 */
-
 VISUAL_END_DECLS
 
 #endif /* _LV_TYPES_H */
