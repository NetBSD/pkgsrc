$NetBSD: patch-jscell.h,v 1.1 2016/12/18 21:54:05 joerg Exp $

--- jscell.h.orig	2016-12-18 15:56:09.131413382 +0000
+++ jscell.h
@@ -40,7 +40,7 @@
 #ifndef jscell_h___
 #define jscell_h___
 
-struct JSCompartment;
+struct JS_FRIEND_API(JSCompartment);
 
 namespace js {
 namespace gc {
