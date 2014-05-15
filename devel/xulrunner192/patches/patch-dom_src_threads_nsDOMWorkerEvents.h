$NetBSD: patch-dom_src_threads_nsDOMWorkerEvents.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- dom/src/threads/nsDOMWorkerEvents.h.orig	2014-05-14 21:49:43.000000000 +0000
+++ dom/src/threads/nsDOMWorkerEvents.h
@@ -74,6 +74,9 @@ public:
   virtual PRBool PreventDefaultCalled() = 0;
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWorkerPrivateEvent,
+                              NS_IDOMWORKERPRIVATEEVENT_IID)
+
 #define NS_FORWARD_NSIDOMEVENT_SPECIAL                                        \
   NS_IMETHOD GetType(nsAString& aType)                                        \
     { return mEvent->GetType(aType); }                                        \
