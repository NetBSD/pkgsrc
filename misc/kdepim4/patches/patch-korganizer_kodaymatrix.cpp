$NetBSD: patch-korganizer_kodaymatrix.cpp,v 1.1 2020/05/14 19:19:56 joerg Exp $

--- korganizer/kodaymatrix.cpp.orig	2020-05-12 20:03:31.118147634 +0000
+++ korganizer/kodaymatrix.cpp
@@ -862,7 +862,7 @@ void KODayMatrix::paintEvent( QPaintEven
       p.setPen( actcol );
     }
     // reset bold font to plain font
-    if ( mEvents.contains( mDays[i] ) > 0 ) {
+    if ( mEvents.contains( mDays[i] ) ) {
       QFont myFont = font();
       myFont.setBold( false );
       p.setFont( myFont );
