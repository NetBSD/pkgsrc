$NetBSD: patch-util.h,v 1.1 2018/02/19 09:51:48 he Exp $

--- util.h.orig	1999-03-27 20:16:58.000000000 +0000
+++ util.h
@@ -7,6 +7,6 @@
 unsigned long getColor(Display*, const char*);
 SuitColor suitColor(Suit);
 
-void makeBitmap(Suit, int, char*);
-void makeOneSymbolBitmap(Suit, char*);
+void makeBitmap(Suit, int, unsigned char*);
+void makeOneSymbolBitmap(Suit, unsigned char*);
 #endif
