$NetBSD: patch-lily_include_translator-group.hh,v 1.1 2013/04/01 12:20:47 joerg Exp $

Issue 2208.

--- lily/include/translator-group.hh.orig	2013-03-31 15:00:25.000000000 +0000
+++ lily/include/translator-group.hh
@@ -43,7 +43,7 @@ struct Translator_method_binding
   void invoke ()
   {
     if (method_)
-      (*method_) (translator_);
+      (translator_->*method_)();
   }
 };
 
