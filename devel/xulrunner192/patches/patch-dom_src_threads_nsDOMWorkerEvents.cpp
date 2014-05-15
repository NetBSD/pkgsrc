$NetBSD: patch-dom_src_threads_nsDOMWorkerEvents.cpp,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- dom/src/threads/nsDOMWorkerEvents.cpp.orig	2014-05-14 21:49:45.000000000 +0000
+++ dom/src/threads/nsDOMWorkerEvents.cpp
@@ -49,9 +49,6 @@
 #include "nsDOMWorkerXHR.h"
 #include "nsDOMWorkerXHRProxy.h"
 
-NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWorkerPrivateEvent,
-                              NS_IDOMWORKERPRIVATEEVENT_IID)
-
 nsDOMWorkerPrivateEvent::nsDOMWorkerPrivateEvent(nsIDOMEvent* aEvent)
 : mEvent(aEvent),
   mProgressEvent(do_QueryInterface(aEvent)),
