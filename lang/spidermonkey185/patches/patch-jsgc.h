$NetBSD: patch-jsgc.h,v 1.1 2016/12/18 21:54:05 joerg Exp $

--- jsgc.h.orig	2016-12-18 15:56:38.171004394 +0000
+++ jsgc.h
@@ -66,7 +66,7 @@
 #include "jsgcstats.h"
 #include "jscell.h"
 
-struct JSCompartment;
+struct JS_FRIEND_API(JSCompartment);
 
 extern "C" void
 js_TraceXML(JSTracer *trc, JSXML* thing);
