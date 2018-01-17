$NetBSD: patch-part_view_kateviewhelpers.cpp,v 1.1 2018/01/17 20:19:58 markd Exp $

Fixes an error when compiling with GCC7:
error: call of overloaded 'abs(uint)' is ambiguous

Backport of https://cgit.kde.org/ktexteditor.git/commit/?id=8b2820b4c95284337b5713ce7f548a456c25279e
from the KF5 ktexteditor.

--- part/view/kateviewhelpers.cpp.orig	2014-10-26 20:17:55.000000000 +0000
+++ part/view/kateviewhelpers.cpp
@@ -1703,7 +1703,7 @@ void KateIconBorder::paintBorder (int /*
       if (realLine > -1) {
         if (m_viewInternal->cache()->viewLine(z).startCol() == 0) {
           if (m_viRelLineNumbersOn && m_view->viInputMode()) {
-            int diff = abs(realLine - currentLine);
+            int diff = abs(realLine - static_cast<int>(currentLine));
             if (diff > 0) {
               p.drawText( lnX + m_maxCharWidth / 2, y, lnWidth - m_maxCharWidth, h,
                           Qt::TextDontClip|Qt::AlignRight|Qt::AlignVCenter, QString("%1").arg(diff) );
