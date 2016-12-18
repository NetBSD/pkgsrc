$NetBSD: patch-jspubtd.h,v 1.1 2016/12/18 21:54:05 joerg Exp $

--- jspubtd.h.orig	2016-12-18 15:57:02.579898362 +0000
+++ jspubtd.h
@@ -162,6 +162,7 @@ typedef struct JSExceptionState  JSExcep
 typedef struct JSLocaleCallbacks JSLocaleCallbacks;
 typedef struct JSSecurityCallbacks JSSecurityCallbacks;
 typedef struct JSONParser        JSONParser;
+struct JS_FRIEND_API(JSCompartment);
 typedef struct JSCompartment     JSCompartment;
 typedef struct JSCrossCompartmentCall JSCrossCompartmentCall;
 typedef struct JSStructuredCloneWriter JSStructuredCloneWriter;
@@ -169,7 +170,9 @@ typedef struct JSStructuredCloneReader J
 typedef struct JSStructuredCloneCallbacks JSStructuredCloneCallbacks;
 
 #ifdef __cplusplus
+class JS_FRIEND_API(JSWrapper);
 typedef class JSWrapper          JSWrapper;
+struct JS_FRIEND_API(JSCrossCompartmentWrapper);
 typedef class JSCrossCompartmentWrapper JSCrossCompartmentWrapper;
 #endif
 
