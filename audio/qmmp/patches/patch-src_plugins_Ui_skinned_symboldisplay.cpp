$NetBSD: patch-src_plugins_Ui_skinned_symboldisplay.cpp,v 1.1 2019/10/01 12:43:04 nia Exp $

Avoid GNUism.

--- src/plugins/Ui/skinned/symboldisplay.cpp.orig	2019-08-27 19:32:14.000000000 +0000
+++ src/plugins/Ui/skinned/symboldisplay.cpp
@@ -32,11 +32,7 @@ SymbolDisplay::SymbolDisplay (QWidget *p
     connect (m_skin, SIGNAL (skinChanged()), this, SLOT (draw()));
     draw();
     for (int i=0; i<m_digits; ++i)
-#if defined(Q_OS_FREEBSD) || defined(Q_OS_WIN) || defined (Q_OS_MAC)
         m_max += 9 * (int) pow(10,i);
-#else
-        m_max += 9 * (int) exp10(i);
-#endif
 }
 
 SymbolDisplay::~SymbolDisplay()
