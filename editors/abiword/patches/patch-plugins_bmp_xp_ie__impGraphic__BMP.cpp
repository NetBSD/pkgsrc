$NetBSD: patch-plugins_bmp_xp_ie__impGraphic__BMP.cpp,v 1.1 2011/02/01 10:48:15 wiz Exp $

Fix build with png-1.5.

--- plugins/bmp/xp/ie_impGraphic_BMP.cpp.orig	2009-06-25 04:02:06.000000000 +0000
+++ plugins/bmp/xp/ie_impGraphic_BMP.cpp
@@ -191,7 +191,10 @@ UT_Error IE_ImpGraphic_BMP::_convertGrap
 
 	/* Clean Up Memory Used */
 		
-	FREEP(m_pPNGInfo->palette);
+	png_colorp palette;
+	int num_palette;
+	png_get_PLTE( m_pPNG, m_pPNGInfo, &palette, &num_palette );
+	FREEP(palette);
 	DELETEP(pBB);
 	png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
    
@@ -313,7 +316,7 @@ UT_Error IE_ImpGraphic_BMP::Initialize_P
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in the png_create_read_struct() earlier.
 	 */
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
@@ -332,7 +335,7 @@ UT_Error IE_ImpGraphic_BMP::Initialize_P
 	UT_Error IE_ImpGraphic_BMP::Convert_BMP_Pallet(UT_ByteBuf* pBB)
 	{
 		/* Reset error handling for libpng */
-		if (setjmp(m_pPNG->jmpbuf))
+		if (setjmp(png_jmpbuf(m_pPNG)))
 		{
 			png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
 			return UT_ERROR;
@@ -372,7 +375,7 @@ UT_Error IE_ImpGraphic_BMP::Initialize_P
 UT_Error IE_ImpGraphic_BMP::Convert_BMP(UT_ByteBuf* pBB)
 {
 	/* Reset error handling for libpng */
-	if (setjmp(m_pPNG->jmpbuf))
+	if (setjmp(png_jmpbuf(m_pPNG)))
 	{
 		png_destroy_write_struct(&m_pPNG, &m_pPNGInfo);
 		return UT_ERROR;
