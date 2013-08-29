$NetBSD: patch-dom_workers_XMLHttpRequestPrivate.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- dom/workers/XMLHttpRequestPrivate.cpp.orig	2013-08-28 16:06:26.000000000 +0000
+++ dom/workers/XMLHttpRequestPrivate.cpp
@@ -1553,19 +1553,19 @@ XMLHttpRequestPrivate::GetAllResponseHea
   mWorkerPrivate->AssertIsOnWorkerThread();
 
   if (mCanceled) {
-    return false;
+    return 0;
   }
 
   if (!mProxy) {
     ThrowDOMExceptionForCode(aCx, INVALID_STATE_ERR);
-    return false;
+    return 0;
   }
 
   nsCString responseHeaders;
   nsRefPtr<GetAllResponseHeadersRunnable> runnable =
     new GetAllResponseHeadersRunnable(mWorkerPrivate, mProxy, responseHeaders);
   if (!runnable->Dispatch(aCx)) {
-    return false;
+    return 0;
   }
 
   return JS_NewStringCopyN(aCx, responseHeaders.get(),
@@ -1578,17 +1578,17 @@ XMLHttpRequestPrivate::GetResponseHeader
   mWorkerPrivate->AssertIsOnWorkerThread();
 
   if (mCanceled) {
-    return false;
+    return 0;
   }
 
   if (!mProxy) {
     ThrowDOMExceptionForCode(aCx, INVALID_STATE_ERR);
-    return false;
+    return 0;
   }
 
   nsDependentJSString header;
   if (!header.init(aCx, aHeader)) {
-    return false;
+    return 0;
   }
 
   nsCString value;
@@ -1596,7 +1596,7 @@ XMLHttpRequestPrivate::GetResponseHeader
     new GetResponseHeaderRunnable(mWorkerPrivate, mProxy,
                                   NS_ConvertUTF16toUTF8(header), value);
   if (!runnable->Dispatch(aCx)) {
-    return false;
+    return 0;
   }
 
   return JS_NewStringCopyN(aCx, value.get(), value.Length());
