$NetBSD: patch-dom_webtransport_api_WebTransportDatagramDuplexStream.cpp,v 1.1 2023/08/28 18:01:47 he Exp $

Make isnan() available via "using std::isnan;", as that's
apparently needed at least on netbsd-10 to bring isnan() into scope.

--- dom/webtransport/api/WebTransportDatagramDuplexStream.cpp.orig	2023-08-14 18:19:46.000000000 +0000
+++ dom/webtransport/api/WebTransportDatagramDuplexStream.cpp
@@ -10,6 +10,8 @@
 #include "mozilla/dom/Promise-inl.h"
 #include "mozilla/dom/WebTransportLog.h"
 
+using std::isnan;
+
 namespace mozilla::dom {
 
 NS_IMPL_CYCLE_COLLECTION_WRAPPERCACHE(WebTransportDatagramDuplexStream, mGlobal,
