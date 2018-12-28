$NetBSD: patch-src_af_gr_xp_gr__Caret.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/gr/xp/gr_Caret.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/gr/xp/gr_Caret.cpp
@@ -30,6 +30,11 @@
 #include "gr_Graphics.h"
 #include "gr_Painter.h"
 #include "ut_debugmsg.h"
+#include <inttypes.h>
+#include <math.h>
+#include <stdio.h>
+#include <time.h>
+
 static const UT_uint32 CURSOR_DELAY_TIME = 10; // milliseconds
 
 #ifdef TOOLKIT_GTK_ALL
@@ -56,6 +61,11 @@ GR_Caret::GR_Caret(GR_Graphics * pG)
 		m_yPoint2(0),
 		m_pClr(NULL),
 		m_pG(pG),
+		m_iWindowWidth(0),
+		m_iWindowHeight(0),
+		m_worker(NULL),
+		m_enabler(NULL),
+		m_blinkTimeout(NULL),
 		m_nDisableCount(1),
 		m_bCursorBlink(true),
 		m_bCursorIsOn(false),
@@ -70,7 +80,10 @@ GR_Caret::GR_Caret(GR_Graphics * pG)
 		m_bRemote(false),
 		m_clrRemote(0,0,0),
 		m_sID(""),
-		m_iCaretNumber(0)
+		m_iCaretNumber(0),
+		m_iLastDrawTime(0),
+		m_iRetry(0),
+		m_bPendingBlink(false)
 {
 	UT_WorkerFactory::ConstructMode outMode = UT_WorkerFactory::NONE;
 	m_worker = static_cast<UT_Timer *>(UT_WorkerFactory::static_constructor
@@ -97,6 +110,11 @@ GR_Caret::GR_Caret(GR_Graphics * pG, con
 		m_yPoint2(0),
 		m_pClr(NULL),
 		m_pG(pG),
+		m_iWindowWidth(0),
+		m_iWindowHeight(0),
+		m_worker(NULL),
+		m_enabler(NULL),
+		m_blinkTimeout(NULL),
 		m_nDisableCount(1),
 		m_bCursorBlink(true),
 		m_bCursorIsOn(false),
@@ -111,7 +129,10 @@ GR_Caret::GR_Caret(GR_Graphics * pG, con
 		m_bRemote(true),
 		m_clrRemote(0,0,0),
 		m_sID(sId),
-		m_iCaretNumber(0)
+		m_iCaretNumber(0),
+		m_iLastDrawTime(0),
+		m_iRetry(0),
+		m_bPendingBlink(false)
 {
 	UT_WorkerFactory::ConstructMode outMode = UT_WorkerFactory::NONE;
 	m_worker = static_cast<UT_Timer *>(UT_WorkerFactory::static_constructor
@@ -145,9 +166,16 @@ GR_Caret::~GR_Caret()
 void GR_Caret::s_work(UT_Worker * _w)
 {
 	GR_Caret * c = static_cast<GR_Caret *>(_w->getInstanceData());
-
+	xxx_UT_DEBUGMSG((" Caret timer called Disable Count = %d \n",c->m_nDisableCount));
 	if (c->m_nDisableCount == 0)
+	{
+#ifdef TOOLKIT_GTK_ALL
+		c->setPendingBlink();
+		c->m_pG->flush(); // set redraw for wayland
+#else
 		c->_blink(false);
+#endif
+	}
 }
 
 /** One-time enabler. */
@@ -170,9 +198,12 @@ void GR_Caret::s_enable(UT_Worker * _w)
 
 void GR_Caret::s_blink_timeout(UT_Worker * _w)
 {
+	return;
+	/*
 	GR_Caret * c = static_cast<GR_Caret *>(_w->getInstanceData());
 	if (c->isEnabled())
 		c->disable();
+	*/
 }
 
 UT_uint32 GR_Caret::_getCursorBlinkTime() const
@@ -241,8 +272,6 @@ void GR_Caret::setCoords(UT_sint32 x, UT
 						 UT_sint32 x2, UT_sint32 y2, UT_uint32 h2,
 						 bool bPointDirection, const UT_RGBColor * pClr)
 {
-	// if visible, then hide while we change positions.
-	_erase();
 
 	m_xPoint = x; m_yPoint = y; m_iPointHeight = h;
 	m_xPoint2 = x2; m_yPoint2 = y2; m_iPointHeight2 = h2;
@@ -270,13 +299,17 @@ void GR_Caret::enable()
 
 	// If the caret is already enabled, just return
 	if (m_nDisableCount == 0)
+	{
+		xxx_UT_DEBUGMSG(("Don't emable disable Count is already zero \n"));
 		return;
-
+	}
 	// Check to see if we still have pending disables.
 	--m_nDisableCount;
-	if (m_nDisableCount)
+	if (m_nDisableCount != 0)
+	{
+		xxx_UT_DEBUGMSG(("Don't emable, disable Count has not reached zero \n"));
 		return;
-
+	}
 	// stop pending enables; in 10 ms, really enable blinking.
 	m_enabler->stop();
 	m_enabler->start();
@@ -326,19 +359,20 @@ void GR_Caret::JustErase(UT_sint32 xPoin
 {
        if(m_bRecursiveDraw)
        {
-	    xxx_UT_DEBUGMSG(("Doing recursive Erase! - abort \n"));
+	    xxx_UT_DEBUGMSG(("Doing recursive Just Erase! - abort \n"));
 	    return;
        }
        if (m_bCursorIsOn && (((xPoint -m_pG->tlu(2)-1) <= m_xPoint) && (xPoint >= (m_xPoint-m_pG->tlu(2))-1)) && ((yPoint - m_pG->tlu(1)) <= m_yPoint) && (yPoint >= (m_yPoint - m_pG->tlu(1))))
        {
+	    xxx_UT_DEBUGMSG(("Doing Just Erase! now \n"));
 	    m_pG->restoreRectangle(m_iCaretNumber*3+0);
 	    if(m_bSplitCaret)
 	    {
 	          m_pG->restoreRectangle(m_iCaretNumber*3+1);
-		  m_pG->restoreRectangle(m_iCaretNumber*3+2);
-		  m_bSplitCaret = false;
+			  m_pG->restoreRectangle(m_iCaretNumber*3+2);
+			  m_bSplitCaret = false;
 	    }
-	    m_bCursorIsOn = !m_bCursorIsOn;
+	    m_bCursorIsOn = false;
 	    m_nDisableCount = 1;
        }
 }
@@ -358,18 +392,42 @@ void GR_Caret::_blink(bool bExplicit)
 	}
         if (!m_bPositionSet)
 		return;
+	if(!m_bPendingBlink)
+		return;
+	struct timespec spec;
+
+    clock_gettime(CLOCK_REALTIME, &spec);
 
+    UT_sint32 s  = spec.tv_sec;
+    long ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
+	long this_time = 1000*s + ms;
+	long time_between = this_time - m_iLastDrawTime;
+	m_iLastDrawTime = this_time;
+    //
+	// If this number is high enough the caret will not blink at all
+	// This places the caret on the screen during rapid moves.
+	//
+	if(time_between < _getCursorBlinkTime()/2) 
+	{
+		m_iRetry++;
+		xxx_UT_DEBUGMSG(("Caret redraw after %d ms \n",time_between));
+	}
+	else
+	{
+		m_iRetry = 0;
+	}
 	m_bRecursiveDraw = true;
 	GR_Painter painter (m_pG, false);
 	m_bRecursiveDraw = false;
 
 	// After any autoblink, we want there to be BLINK_TIME 
 	// until next autoblink.
+	/*
 	if (!bExplicit)
 	{ 
 		m_worker->stop(); m_worker->start();
 	}
-
+	*/
 	// Blink if: (a) _blink explicitly called (not autoblink); or
 	//           (b) autoblink and caret blink enabled; or
 	//           (c) autoblink, caret blink disabled, caret is off
@@ -380,6 +438,7 @@ void GR_Caret::_blink(bool bExplicit)
 
 		if (m_bCursorIsOn)
 		{
+			xxx_UT_DEBUGMSG(("Clear Caret reTry %d \n",m_iRetry));
 			m_pG->restoreRectangle(m_iCaretNumber*3+0);
 
 			if(m_bSplitCaret)
@@ -388,6 +447,7 @@ void GR_Caret::_blink(bool bExplicit)
 				m_pG->restoreRectangle(m_iCaretNumber*3+2);
 				m_bSplitCaret = false;
 			}
+			m_bCursorIsOn = false;
 		}
 		else
 		{
@@ -413,7 +473,9 @@ void GR_Caret::_blink(bool bExplicit)
 					   m_yPoint+m_pG->tlu(1),
 					   m_pG->tlu(5),
 					   m_iPointHeight+m_pG->tlu(2));
+			m_bRecursiveDraw = false;
 			m_pG->allCarets()->JustErase(m_xPoint,m_yPoint);
+			m_bRecursiveDraw = true;
 			m_pG->saveRectangle(r0,m_iCaretNumber*3+0);
 
 			if((m_xPoint != m_xPoint2) || (m_yPoint != m_yPoint2))
@@ -446,7 +508,7 @@ void GR_Caret::_blink(bool bExplicit)
 			if(m_bCaret1OnScreen)
 			{
 				// draw the primary caret
-				xxx_UT_DEBUGMSG(("blink cursor turned on \n")); 
+				xxx_UT_DEBUGMSG(("Draw Caret reTry %d \n",m_iRetry)); 
 
 				UT_sint32 x1 = m_xPoint + iDelta * m_pG->tlu(1);
 				UT_sint32 x2 = m_xPoint;
@@ -463,6 +525,7 @@ void GR_Caret::_blink(bool bExplicit)
 								 m_yPoint + m_pG->tlu(1),
 								 x2, 
 								 m_yPoint + m_iPointHeight + m_pG->tlu(1));
+				m_bCursorIsOn = true;
 			}
 			
 			if(m_bSplitCaret)
@@ -499,6 +562,7 @@ void GR_Caret::_blink(bool bExplicit)
 										 m_xPoint + m_pG->tlu(2),
 										 m_yPoint + m_pG->tlu(2));
 					}
+					m_bCursorIsOn = true;
 				}
 				
 				// Now we deal with the secondary caret needed on ltr-rtl boundary
@@ -557,25 +621,54 @@ void GR_Caret::_blink(bool bExplicit)
 										 m_xPoint2 /*- m_pG->tlu(1)*/,
 										 m_yPoint2 + m_pG->tlu(2));
 					}
+					m_bCursorIsOn = true;
 				}
 				
 			}
 			
 		}
 
-		m_bCursorIsOn = !m_bCursorIsOn;
  		m_pG->setColor(oldColor);
 		m_bRecursiveDraw = false;
 	}
-	m_pG->flush();
+	//
+	// Places the caret on the screen during rapid moves like pressing the arrow keys
+	//
+	if(m_iRetry == 0)
+		m_bPendingBlink = false;
 }
 
+//
+// Tell the widget redraw know we only need to blink on this cycle
+//
+void GR_Caret::setPendingBlink()
+{
+	xxx_UT_DEBUGMSG(("Pending blink set in GR_CARET \n"));
+	m_bPendingBlink = true;
+}
+
+//
+// Returns true if we did a blink
+//
+bool GR_Caret::doBlinkIfNeeded()
+{
+	if(!m_bPendingBlink)
+	{
+		return false;
+	}
+	_blink(true);
+	m_bPendingBlink = false;
+	return true;
+}
 /*!
  * Only call this is you are absolutely certain you need it!
  */
 void GR_Caret::forceDraw(void)
 {
-	_blink(true);
+	if(m_nDisableCount < 2)
+	{
+		_blink(true);
+	}
 }
 
 void GR_Caret::resetBlinkTimeout(void)
