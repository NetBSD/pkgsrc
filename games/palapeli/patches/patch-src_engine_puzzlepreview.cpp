$NetBSD: patch-src_engine_puzzlepreview.cpp,v 1.1 2015/10/05 05:09:05 richard Exp $
avoid call of overloaded sqrt error (on SunOS)
--- src/engine/puzzlepreview.cpp.orig	2014-07-18 08:06:37.000000000 +0000
+++ src/engine/puzzlepreview.cpp
@@ -75,7 +75,7 @@ void Palapeli::PuzzlePreview::loadImageF
 	setImage(md.image);
 	setWindowTitle(i18n("%1 - Preview", md.name));
 	// Set hover-zoom so that 3x3 pieces would be visible on a square grid.
-	m_hoverZoom = sqrt(md.pieceCount)/3.0;
+	m_hoverZoom = std::sqrt(md.pieceCount)/3.0;
 	if (m_hoverZoom < 1)
 		m_hoverZoom = 1;
 }
