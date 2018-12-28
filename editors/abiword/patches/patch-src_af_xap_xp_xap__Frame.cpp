$NetBSD: patch-src_af_xap_xp_xap__Frame.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/xap/xp/xap_Frame.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/xap/xp/xap_Frame.cpp
@@ -505,7 +505,7 @@ void /* static*/ XAP_FrameImpl::viewAuto
 		pFrameImpl->m_ViewAutoUpdaterID = 0;
 		DELETEP(pFrameImpl->m_ViewAutoUpdater);
 		pView->draw();
-
+		pG->flush();
 		return;
 	}
 	if(!pView->isLayoutFilling() && !pFrameImpl->m_pFrame->m_bFirstDraw)
@@ -514,6 +514,7 @@ void /* static*/ XAP_FrameImpl::viewAuto
 		pG->setCursor(GR_Graphics::GR_CURSOR_WAIT);
 		pFrameImpl->_setCursor(GR_Graphics::GR_CURSOR_WAIT);
 		pFrameImpl->m_pFrame->setStatusMessage ( static_cast<const gchar *>(msg.c_str()) );
+		pG->flush();
 		return;
 	}
 	GR_Graphics * pG = pView->getGraphics();
@@ -534,6 +535,7 @@ void /* static*/ XAP_FrameImpl::viewAuto
 			pView->updateScreen();
 		}
 	}
+	pG->flush();
 }
 
 UT_RGBColor XAP_Frame::getColorSelBackground () const
