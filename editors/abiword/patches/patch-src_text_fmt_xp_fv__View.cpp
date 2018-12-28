$NetBSD: patch-src_text_fmt_xp_fv__View.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/text/fmt/xp/fv_View.cpp.orig	2016-01-23 21:00:21.000000000 +0000
+++ src/text/fmt/xp/fv_View.cpp
@@ -3105,11 +3105,15 @@ bool FV_View::isSelectionEmpty(void) con
 {
 	if(m_FrameEdit.isActive() && m_FrameEdit.isImageWrapper() )
 	{
-	        return false;
+		if (m_pG)
+			m_pG->allCarets()->disable(true);
+		return false;
 	}
 	if(m_FrameEdit.isActive() && (m_FrameEdit. getFrameEditMode() >= FV_FrameEdit_RESIZE_INSERT))
 	{
-	        return false;
+		if (m_pG)
+			m_pG->allCarets()->disable(true);
+		return false;
 	}
 	if (!m_Selection.isSelected())
 	{
@@ -3124,6 +3128,8 @@ bool FV_View::isSelectionEmpty(void) con
 		{
 			return true;
 		}
+		if (m_pG)
+			m_pG->allCarets()->disable(true);
 		return false;
 	}
 	PT_DocPosition curPos = getPoint();
@@ -3131,7 +3137,8 @@ bool FV_View::isSelectionEmpty(void) con
 	{
 		return true;
 	}
-
+	if (m_pG)
+		m_pG->allCarets()->disable(true);
 	return false;
 }
 
