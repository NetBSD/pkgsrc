$NetBSD: patch-src_text__object.h,v 1.1.1.1 2012/05/13 08:42:20 imil Exp $

Enable NetBSD as a suitable platform.

--- src/text_object.h.orig	2012-05-03 21:08:27.000000000 +0000
+++ src/text_object.h
@@ -166,9 +166,7 @@ enum text_object_type {
 	OBJ_wireless_link_qual_perc,
 	OBJ_wireless_link_bar,
 #endif /* __linux__ */
-#if defined(__FreeBSD__) || defined(__linux__)
 	OBJ_if_up,
-#endif
 	OBJ_if_empty,
 	OBJ_if_match,
 	OBJ_if_existing,
@@ -311,7 +309,7 @@ enum text_object_type {
 	OBJ_pop3_unseen,
 	OBJ_pop3_used,
 #if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
-		|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
+	|| defined(__OpenBSD__)) && (defined(i386) || defined(__i386__))
 	OBJ_apm_adapter,
 	OBJ_apm_battery_time,
 	OBJ_apm_battery_life,
