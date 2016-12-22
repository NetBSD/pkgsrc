$NetBSD: patch-src_amazon.cc,v 1.1 2016/12/22 20:58:40 joerg Exp $

operator bool of RefPtr<> is explicit, so force the conversion.

--- src/amazon.cc.orig	2016-12-22 12:54:02.224939332 +0000
+++ src/amazon.cc
@@ -121,7 +121,7 @@ namespace Bmp
       {
         cover = RefPtr<Gdk::Pixbuf> (0);
       }
-      return cover;
+      return bool(cover);
     }
     
     RefPtr<Gdk::Pixbuf>
