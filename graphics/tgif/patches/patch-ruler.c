$NetBSD: patch-ruler.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- ruler.c.orig	2011-05-16 16:21:59.000000000 +0000
+++ ruler.c
@@ -523,6 +523,7 @@ void DrawHRuleTick(XOff)
 
 static
 void DrawVRuleTick(YOff)
+    int YOff;
 {
    XDrawLine(mainDisplay, vRuleWindow, revDefaultGC, 0, YOff, rulerLen, YOff);
 }
