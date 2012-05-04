$NetBSD: patch-src_pslib.c,v 1.1 2012/05/04 16:30:28 joerg Exp $

--- src/pslib.c.orig	2012-04-27 21:05:22.000000000 +0000
+++ src/pslib.c
@@ -5256,7 +5256,7 @@ PS_end_font(PSDoc *psdoc) {
 /* PS_begin_glyph() {{{
  * starts a new glyph
  */
-PSLIB_API int PSLIB_CALL
+PSLIB_API void PSLIB_CALL
 PS_begin_glyph(PSDoc *psdoc, const char *glyphname, double wx, double llx, double lly, double urx, double ury) {
 	if(NULL == psdoc) {
 		ps_error(psdoc, PS_RuntimeError, _("PSDoc is null."));
