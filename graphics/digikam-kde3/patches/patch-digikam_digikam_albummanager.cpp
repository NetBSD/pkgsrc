$NetBSD: patch-digikam_digikam_albummanager.cpp,v 1.1 2012/07/03 18:08:58 joerg Exp $

--- digikam/digikam/albummanager.cpp.orig	2012-07-03 15:09:03.000000000 +0000
+++ digikam/digikam/albummanager.cpp
@@ -1579,16 +1579,14 @@ void AlbumManager::slotDatesJobData(KIO:
 
         // Check if Year Album already exist.
         DAlbum *yAlbum = 0;
-        AlbumIterator it(d->rootDAlbum);
-        while (it.current())
+        for (AlbumIterator it2(d->rootDAlbum); it2.current(); ++it2)
         {
-            DAlbum* a = (DAlbum*)(*it);
+            DAlbum* a = (DAlbum*)(*it2);
             if (a->date() == QDate(year, 1, 1) && a->range() == DAlbum::Year)
             {
                 yAlbum = a;
                 break;
             }
-            ++it;
         }
 
         // If no, create Year album.
