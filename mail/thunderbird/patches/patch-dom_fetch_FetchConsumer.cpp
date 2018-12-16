$NetBSD: patch-dom_fetch_FetchConsumer.cpp,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- dom/fetch/FetchConsumer.cpp.orig	2018-12-04 23:11:45.000000000 +0000
+++ dom/fetch/FetchConsumer.cpp
@@ -616,7 +616,7 @@ FetchBodyConsumer<Derived>::ContinueCons
   RefPtr<Promise> localPromise = mConsumePromise.forget();
 
   RefPtr<FetchBodyConsumer<Derived>> self = this;
-  auto autoReleaseObject = mozilla::MakeScopeExit([&] {
+  auto autoReleaseObject = mozilla::MakeScopeExit([self] {
     self->ReleaseObject();
   });
 
