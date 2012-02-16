$NetBSD: patch-src_declare.h,v 1.1 2012/02/16 11:37:27 hans Exp $

--- src/declare.h.orig	2006-07-07 08:54:24.000000000 +0200
+++ src/declare.h	2009-12-26 00:46:20.874454893 +0100
@@ -25,6 +25,7 @@
 #ifndef DECLARE_H
 #define DECLARE_H
 #include "md.h"
+#undef CS
 /*--------------------------------------------------------------------------*/
 class CS;
 class CARD;
