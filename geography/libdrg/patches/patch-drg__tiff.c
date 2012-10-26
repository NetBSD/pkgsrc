$NetBSD: patch-drg__tiff.c,v 1.1 2012/10/26 20:41:00 joerg Exp $

--- drg_tiff.c.orig	2012-10-26 15:50:54.000000000 +0000
+++ drg_tiff.c
@@ -206,7 +206,7 @@ drgp_ensure_valid(drg_t *drgp)
  * per northing per map, or about 1k times for a full-screen display.
  */
 
-inline int
+static inline int
 drg_tiff_valid_northing(drg_t *drgp, double northing)
 {
   return( drgp &&
@@ -222,7 +222,7 @@ drg_tiff_valid_northing(drg_t *drgp, dou
  * case (1:25000, 1:100000), it's better to use the next smaller scale
  * map than to subsample by 4.
  */
-inline int
+static inline int
 drg_scale_valid(drg_t *drgp, double scale)
 {
   int ok;
@@ -563,7 +563,7 @@ drg_tiff_start_line()
 /*
  * Open file, else return 0
  */
-inline int
+static inline int
 drg_tiff_ensure_open(drg_t *drgp)
 {
   int32_t length;
@@ -610,7 +610,7 @@ drg_tiff_ensure_open(drg_t *drgp)
 /*
  * Allocate strip buffer, else return 0;
  */
-inline int
+static inline int
 drg_tiff_ensure_scanline_buf(drg_t *drgp)
 {
   if ( ! drg_tiff_ensure_open(drgp) ) return 0;
@@ -626,7 +626,7 @@ drg_tiff_ensure_scanline_buf(drg_t *drgp
   return 1;
 }
 
-inline int
+static inline int
 drg_tiff_ensure_scanline_number(drg_t *drgp, int scanline)
 {
   int i;
