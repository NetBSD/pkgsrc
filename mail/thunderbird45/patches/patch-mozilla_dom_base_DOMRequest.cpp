$NetBSD: patch-mozilla_dom_base_DOMRequest.cpp,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/dom/base/DOMRequest.cpp.orig	2016-04-07 21:33:22.000000000 +0000
+++ mozilla/dom/base/DOMRequest.cpp
@@ -20,7 +20,6 @@ using mozilla::dom::DOMError;
 using mozilla::dom::DOMRequest;
 using mozilla::dom::DOMRequestService;
 using mozilla::dom::DOMCursor;
-using mozilla::dom::Promise;
 using mozilla::dom::AutoJSAPI;
 
 DOMRequest::DOMRequest(nsPIDOMWindow* aWindow)
