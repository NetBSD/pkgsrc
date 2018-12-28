$NetBSD: patch-src_af_gr_xp_gr__Caret.h,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/gr/xp/gr_Caret.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/gr/xp/gr_Caret.h
@@ -67,7 +67,8 @@ public:
 	void                            setRemoteColor(UT_RGBColor clrRemote);
 
 	void							resetBlinkTimeout(void);
-
+	void                            setPendingBlink(void);
+	bool                            doBlinkIfNeeded(void);
 private:
 	GR_Caret(); // no impl
 	GR_Caret(const GR_Caret& rhs);			// no impl.
@@ -121,6 +122,9 @@ private:
 	UT_RGBColor						m_clrRemote;
 	std::string				        m_sID;
 	UT_sint32						m_iCaretNumber;
+	long                                                    m_iLastDrawTime;
+	UT_sint32                                               m_iRetry;
+	bool                                                    m_bPendingBlink;
 };
 
 class ABI_EXPORT GR_CaretDisabler
