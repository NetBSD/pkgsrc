$NetBSD: patch-kipi-plugins_flickrexport_imageslist.cpp,v 1.1 2012/10/26 20:38:24 joerg Exp $

--- kipi-plugins/flickrexport/imageslist.cpp.orig	2012-10-26 17:28:12.000000000 +0000
+++ kipi-plugins/flickrexport/imageslist.cpp
@@ -228,15 +228,12 @@ void ImagesList::slotAddImages(const KUR
 
         bool find = false;
 
-        QListViewItemIterator it(d->listView);
-        while (it.current())
+        for (QListViewItemIterator it2(d->listView); it2.current(); ++it2)
         {
-            ImagesListViewItem* item = dynamic_cast<ImagesListViewItem*>(*it);
+            ImagesListViewItem* item = dynamic_cast<ImagesListViewItem*>(*it2);
 
             if (item->url() == imageUrl)
                 find = true;
-
-            ++it;
         }
 
         if (!find)
