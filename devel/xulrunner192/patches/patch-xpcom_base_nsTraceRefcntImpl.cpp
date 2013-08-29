$NetBSD: patch-xpcom_base_nsTraceRefcntImpl.cpp,v 1.2 2013/08/29 12:56:49 joerg Exp $

--- xpcom/base/nsTraceRefcntImpl.cpp.orig	2012-03-06 14:45:48.000000000 +0000
+++ xpcom/base/nsTraceRefcntImpl.cpp
@@ -1175,7 +1175,7 @@ NS_LogCOMPtrAddRef(void* aCOMPtr, nsISup
 {
 #if defined(NS_IMPL_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
@@ -1216,7 +1216,7 @@ NS_LogCOMPtrRelease(void* aCOMPtr, nsISu
 {
 #if defined(NS_IMPL_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
@@ -1347,7 +1347,7 @@ nsTraceRefcntImpl::LogReleaseCOMPtr(void
   return NS_OK;
 }
 
-static const nsTraceRefcntImpl kTraceRefcntImpl;
+static nsTraceRefcntImpl kTraceRefcntImpl;
 
 NS_METHOD
 nsTraceRefcntImpl::Create(nsISupports* outer, const nsIID& aIID, void* *aInstancePtr)
