$NetBSD: patch-style_Collector.h,v 1.1 2020/04/30 23:46:13 joerg Exp $

See Makefile.

--- style/Collector.h.orig	2020-04-30 00:27:45.776360891 +0000
+++ style/Collector.h
@@ -140,7 +140,7 @@ void *Collector::allocateObject(bool has
 {
   if (freePtr_ == &allObjectsList_)
     makeSpace();
-  Object *tem = freePtr_;
+  Object * volatile tem = freePtr_;
   freePtr_ = freePtr_->next();
   tem->setColor(currentColor_);
   tem->hasFinalizer_ = hasFinalizer;
