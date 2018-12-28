$NetBSD: patch-src_text_fmt_xp_fl__SectionLayout.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/text/fmt/xp/fl_SectionLayout.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/text/fmt/xp/fl_SectionLayout.cpp
@@ -1921,6 +1921,9 @@ void fl_DocSectionLayout::updateLayout(b
 		checkAndRemovePages();
 		addValidPages();
 	}
+	xxx_UT_DEBUGMSG(("Doing fl_DocSectionLayout::updateLayout here %p view %p \n",this, m_pLayout->getView()));
+	m_pLayout->getView()->getGraphics()->allCarets()->setPendingBlink(); // place caret after entry
+	m_pLayout->getView()->getGraphics()->flush(); // schedule redraw for Wayland
 }
 
 void fl_DocSectionLayout::setNeedsSectionBreak(bool bSet, fp_Page * pPage)
