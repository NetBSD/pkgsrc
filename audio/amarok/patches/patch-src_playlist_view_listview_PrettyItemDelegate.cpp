$NetBSD: patch-src_playlist_view_listview_PrettyItemDelegate.cpp,v 1.1 2012/03/20 10:28:29 markd Exp $

--- src/playlist/view/listview/PrettyItemDelegate.cpp.orig	2011-12-15 07:36:48.000000000 +0000
+++ src/playlist/view/listview/PrettyItemDelegate.cpp
@@ -460,7 +460,7 @@ void Playlist::PrettyItemDelegate::paint
                 else
                     ratingAlignment = Qt::AlignCenter;
 
-                Amarok::KRatingPainter::paintRating( painter, QRect( currentItemX, rowOffsetY, itemWidth, rowHeight ), ratingAlignment, rating, rating );
+                KRatingPainter::paintRating( painter, QRect( currentItemX, rowOffsetY, itemWidth, rowHeight ), ratingAlignment, rating, rating );
 
             }
             else if ( value == Divider )
