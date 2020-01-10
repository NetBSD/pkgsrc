$NetBSD: patch-libbrasero-utils_brasero-misc.h,v 1.1 2020/01/10 21:18:21 joerg Exp $

--- libbrasero-utils/brasero-misc.h.orig	2020-01-08 23:07:33.551904733 +0000
+++ libbrasero-utils/brasero-misc.h
@@ -55,7 +55,7 @@ brasero_utils_set_use_debug (gboolean ac
 void
 brasero_utils_debug_message (const gchar *location,
 			     const gchar *format,
-			     ...);
+			     ...) G_GNUC_PRINTF(2,3);
 
 #define BRASERO_UTILS_LOG(format, ...)						\
 	brasero_utils_debug_message (G_STRLOC,					\
