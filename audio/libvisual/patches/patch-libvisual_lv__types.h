$NetBSD: patch-libvisual_lv__types.h,v 1.2 2012/03/10 09:19:32 sbd Exp $

--- libvisual/lv_types.h.orig	2006-02-13 20:54:08.000000000 +0000
+++ libvisual/lv_types.h
@@ -26,7 +26,7 @@
 
 #include <libvisual/lv_defines.h>
 
-#if defined(VISUAL_OS_WIN32)
+#if defined(VISUAL_OS_WIN32) || defined(__linux__)
 #include <stdint.h>
 #else
 #include <sys/types.h>
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
