$NetBSD: patch-src_af_gr_xp_gr__Graphics.h,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/gr/xp/gr_Graphics.h.orig	2015-04-02 03:09:13.000000000 +0000
+++ src/af/gr/xp/gr_Graphics.h
@@ -364,7 +364,9 @@ class ABI_EXPORT AllCarets
 						  const UT_RGBColor * pClr = NULL);
 	void		setInsertMode (bool mode);
 	void		forceDraw(void);
-
+	bool        doBlinkIfNeeded(void);
+	void        setPendingBlink(void);
+	
  private:
 	GR_Graphics * m_pG;
 	GR_Caret **    m_pLocalCaret;
