$NetBSD: patch-js_src_jsproxy.h,v 1.1 2012/11/11 22:26:00 joerg Exp $

--- js/src/jsproxy.h.orig	2012-10-24 14:32:54.000000000 +0000
+++ js/src/jsproxy.h
@@ -13,7 +13,7 @@
 
 namespace js {
 
-class Wrapper;
+class JS_PUBLIC_API(Wrapper);
 
 /*
  * A proxy is a JSObject that implements generic behavior by providing custom
