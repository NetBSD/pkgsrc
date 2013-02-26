$NetBSD: patch-src_ObservableQueue.h,v 1.1 2013/02/26 11:02:03 joerg Exp $

--- src/ObservableQueue.h.orig	2013-02-25 15:42:21.000000000 +0000
+++ src/ObservableQueue.h
@@ -331,14 +331,14 @@ CObservableQueue<ValueType>::~CObservabl
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverAdded( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STARTING ), o );
+	this->NotifyObservers( EventType( EventType::STARTING ), o );
 }
 
 
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverRemoved( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STOPPING ), o );
+	this->NotifyObservers( EventType( EventType::STOPPING ), o );
 }
 
 
