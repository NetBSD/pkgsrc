$NetBSD: patch-lily_translator-dispatch-list.cc,v 1.1 2013/04/01 12:20:47 joerg Exp $

Issue 2208.

--- lily/translator-dispatch-list.cc.orig	2013-03-31 15:00:57.000000000 +0000
+++ lily/translator-dispatch-list.cc
@@ -32,7 +32,7 @@ Engraver_dispatch_list::apply (Grob_info
       if (e.engraver_ == origin)
         continue;
 
-      (*e.function_) (e.engraver_, gi);
+      (e.engraver_->*e.function_)(gi);
     }
 }
 
