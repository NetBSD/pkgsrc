$NetBSD: patch-mozilla_dom_events_MessageEvent.h,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/dom/events/MessageEvent.h.orig	2015-11-08 13:37:35.000000000 +0000
+++ mozilla/dom/events/MessageEvent.h
@@ -15,9 +15,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePort;
 
 /**
