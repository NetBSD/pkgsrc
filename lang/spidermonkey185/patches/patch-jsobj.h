$NetBSD: patch-jsobj.h,v 1.1 2016/12/18 21:54:05 joerg Exp $

--- jsobj.h.orig	2016-12-18 16:00:57.734918038 +0000
+++ jsobj.h
@@ -67,7 +67,7 @@
 
 namespace js {
 
-class JSProxyHandler;
+class JS_FRIEND_API(JSProxyHandler);
 class AutoPropDescArrayRooter;
 
 namespace mjit {
