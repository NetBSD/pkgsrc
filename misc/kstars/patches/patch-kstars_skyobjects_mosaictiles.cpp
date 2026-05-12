$NetBSD: patch-kstars_skyobjects_mosaictiles.cpp,v 1.1 2026/05/12 06:52:27 wiz Exp $

Fix build on NetBSD 11.
https://bugs.kde.org/show_bug.cgi?id=520064

--- kstars/skyobjects/mosaictiles.cpp.orig	2026-05-12 06:37:40.254756893 +0000
+++ kstars/skyobjects/mosaictiles.cpp
@@ -535,7 +535,7 @@ void MosaicTiles::draw(QPainter *painter)
                                   .arg(tile->skyCenter.ra0().toHMSString(), tile->skyCenter.dec0().toDMSString()));
                 painter->drawText(oneRect, Qt::AlignHCenter | Qt::AlignBottom, QString("%1%2°")
                                   .arg(tile->rotation >= 0.01 ? '+' : tile->rotation <= -0.01 ? '-' : '~')
-                                  .arg(abs(tile->rotation), 5, 'f', 2));
+                                  .arg(fabs(tile->rotation), 5, 'f', 2));
 
                 painter->restore();
             }
