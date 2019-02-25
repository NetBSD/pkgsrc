$NetBSD: patch-dom_fetch_FetchConsumer.cpp,v 1.1 2019/02/25 15:32:24 wiz Exp $

--- dom/fetch/FetchConsumer.cpp.orig	2019-02-23 20:00:40.000000000 +0000
+++ dom/fetch/FetchConsumer.cpp
@@ -560,7 +560,7 @@ void FetchBodyConsumer<Derived>::Continu
 
   RefPtr<FetchBodyConsumer<Derived>> self = this;
   auto autoReleaseObject =
-      mozilla::MakeScopeExit([&] { self->ReleaseObject(); });
+      mozilla::MakeScopeExit([self] { self->ReleaseObject(); });
 
   if (aShuttingDown) {
     // If shutting down, we don't want to resolve any promise.
