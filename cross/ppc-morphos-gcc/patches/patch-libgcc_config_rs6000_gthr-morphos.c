$NetBSD: patch-libgcc_config_rs6000_gthr-morphos.c,v 1.1 2025/06/15 12:51:36 js Exp $

--- libgcc/config/rs6000/gthr-morphos.c.orig	2025-06-15 12:32:32.655339102 +0000
+++ libgcc/config/rs6000/gthr-morphos.c
@@ -1243,7 +1243,7 @@ int __gthr_morphos_mutex_unlock (__gthre
 }
 
 
-static inline void UNIXTIME_TO_AMIGATIME(const struct TimeVal *from, struct TimeVal *to)
+static inline void UNIXTIME_TO_AMIGATIME(const struct timeval *from, struct timeval *to)
 {
 	const ULONG unix_to_amiga = (8 * 365 + 2) * 24 * 60 * 60;
 
