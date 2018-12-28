$NetBSD: patch-src_text_fmt_xp_fv__View__protected.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/text/fmt/xp/fv_View_protected.cpp.orig	2016-10-21 00:39:16.000000000 +0000
+++ src/text/fmt/xp/fv_View_protected.cpp
@@ -4478,7 +4478,6 @@ void FV_View::_draw(UT_sint32 x, UT_sint
 					 "\t\twith [yScrollOffset %d][windowHeight %d][bDirtyRunsOnly %d]\n",
 					 x,y,width,height,bClip,
 					 m_yScrollOffset,getWindowHeight(),bDirtyRunsOnly));
-
 	if(m_pViewDoubleBufferingObject != NULL && m_pViewDoubleBufferingObject->getCallDrawOnlyAtTheEnd())
 	{
 		// record this call's arguments and return
@@ -4727,12 +4726,19 @@ void FV_View::_draw(UT_sint32 x, UT_sint
 		// advance to the next page
 		pPage = pPage -> getNext();
 	}
-
 	if (bClip)
 	{
 		m_pG->setClipRect(NULL);
 	}
-
+	//
+	// Look if we have to blink the caret
+	//
+	xxx_UT_DEBUGMSG(("Doing _draw bDirtyRunsOnly %d \n",bDirtyRunsOnly));
+	
+	if(m_pG->allCarets()->doBlinkIfNeeded())
+	{
+		xxx_UT_DEBUGMSG(("Pending blink drawn has bDirtyRunsOnly %d \n",bDirtyRunsOnly));
+	}
 	xxx_UT_DEBUGMSG(("End _draw\n"));
 }
 
@@ -4816,6 +4822,14 @@ void FV_View::_setPoint(PT_DocPosition p
 		  m_countDisable++;
 		}
 	}
+	
+	if(m_pG)
+	{
+		xxx_UT_DEBUGMSG(("Schedule redraw in _setPoint \n"));
+		m_pG->allCarets()->setPendingBlink();
+		m_pG->flush(); // scedule a redraw for Wayland
+	}
+
 }
 
 
