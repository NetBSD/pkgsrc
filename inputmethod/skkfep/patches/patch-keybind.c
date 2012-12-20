$NetBSD: patch-keybind.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- keybind.c.orig	2012-12-20 14:38:47.000000000 +0000
+++ keybind.c
@@ -58,8 +58,7 @@ setKanaKey()
     KAlphaInputKeymap[k] = kfFix;
 }
 
-setEscape(b)
-EscapeBehavior b;
+void setEscape(EscapeBehavior b)
 {
     if (b == ToggleEsc) return;
     if (b == NoEsc) {
