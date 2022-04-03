$NetBSD: patch-pdf2djvu.cc,v 1.6 2022/04/03 10:09:58 wiz Exp $

poppler-22.03 fix from upstream.

--- pdf2djvu.cc.orig	2021-11-22 17:38:31.000000000 +0000
+++ pdf2djvu.cc
@@ -89,7 +89,7 @@ static int get_page_for_goto_link(pdf::l
 #endif
   }
   else
-    dest.reset(orig_dest->copy());
+    dest.reset(new pdf::link::Destination(*orig_dest));
   if (dest.get() != nullptr)
   {
     int page;
