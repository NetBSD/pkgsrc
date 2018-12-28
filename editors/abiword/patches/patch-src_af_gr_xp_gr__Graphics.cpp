$NetBSD: patch-src_af_gr_xp_gr__Graphics.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/gr/xp/gr_Graphics.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/gr/xp/gr_Graphics.cpp
@@ -185,6 +185,20 @@ void		AllCarets::setBlink(bool bBlink)
 	}
 }
 
+bool AllCarets::doBlinkIfNeeded(void)
+{
+	bool bBlinked = false;
+	if((*m_pLocalCaret))
+	{
+		bBlinked = (*m_pLocalCaret)->doBlinkIfNeeded();
+		for(UT_sint32 i =0; i< m_vecCarets->getItemCount();i++)
+		{
+			m_vecCarets->getNthItem(i)->forceDraw();
+		}
+	}
+	return bBlinked;
+}
+
 void        AllCarets::setWindowSize(UT_uint32 width, UT_uint32 height)
 {
 	if((*m_pLocalCaret))
@@ -195,6 +209,12 @@ void        AllCarets::setWindowSize(UT_
 	}
 }
 
+void        AllCarets::setPendingBlink(void)
+{
+	if((*m_pLocalCaret))
+		(*m_pLocalCaret)->setPendingBlink();
+}
+
 void		AllCarets::setCoords(UT_sint32 x, UT_sint32 y, UT_uint32 h,
 						  UT_sint32 x2, UT_sint32 y2, UT_uint32 h2, 
 						  bool bPointDirection, 
