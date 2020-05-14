$NetBSD: patch-src_editorkeysequencemanager.cpp,v 1.1 2020/05/14 19:05:27 joerg Exp $

--- src/editorkeysequencemanager.cpp.orig	2020-05-13 00:28:34.099099328 +0000
+++ src/editorkeysequencemanager.cpp
@@ -203,7 +203,7 @@ bool Recorder::eventFilter(QObject* /* o
 	{
 		for(int i = 0; i < s.length(); ++i) {
 			QString toCheck = s.right(s.length() - i);
-			if(m_watchedKeySequencesList.contains(toCheck) > 0) {
+			if(m_watchedKeySequencesList.contains(toCheck)) {
  				m_view->document()->removeText(KTextEditor::Range(m_oldLine, m_oldCol - (s.length() - i - 1), m_oldLine, m_oldCol));
 				m_typedSequence.clear(); // clean m_typedSequence to avoid wrong action triggering if one presses keys without printable character
 				emit detectedTypedKeySequence(toCheck);
