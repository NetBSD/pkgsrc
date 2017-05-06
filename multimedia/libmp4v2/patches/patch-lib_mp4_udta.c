$NetBSD: patch-lib_mp4_udta.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/udta.c.orig	2001-08-30 16:23:13.000000000 +0000
+++ lib/mp4/udta.c
@@ -88,7 +88,7 @@ int quicktime_read_udta(quicktime_t *fil
 	return result;
 }
 
-int quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
+void quicktime_write_udta(quicktime_t *file, quicktime_udta_t *udta)
 {
 	quicktime_atom_t atom, subatom;
 
