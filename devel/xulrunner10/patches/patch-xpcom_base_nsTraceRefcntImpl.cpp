$NetBSD: patch-xpcom_base_nsTraceRefcntImpl.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- xpcom/base/nsTraceRefcntImpl.cpp.orig	2013-08-28 12:34:21.000000000 +0000
+++ xpcom/base/nsTraceRefcntImpl.cpp
@@ -1187,7 +1187,7 @@ NS_LogCOMPtrAddRef(void* aCOMPtr, nsISup
 {
 #if defined(NS_IMPL_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
@@ -1228,7 +1228,7 @@ NS_LogCOMPtrRelease(void* aCOMPtr, nsISu
 {
 #if defined(NS_IMPL_REFCNT_LOGGING) && defined(HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR)
   // Get the most-derived object.
-  void *object = dynamic_cast<void *>(aObject);
+  void *object = reinterpret_cast<void *>(aObject);
 
   // This is a very indirect way of finding out what the class is
   // of the object being logged.  If we're logging a specific type,
