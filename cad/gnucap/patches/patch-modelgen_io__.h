$NetBSD: patch-modelgen_io__.h,v 1.1 2012/02/16 11:37:27 hans Exp $

--- modelgen/io_.h.orig	2006-07-07 08:54:23.000000000 +0200
+++ modelgen/io_.h	2009-12-26 00:41:01.207595711 +0100
@@ -25,6 +25,7 @@
 #ifndef IO_H
 #define IO_H
 #include "l_lib.h"
+#undef CS
 /*--------------------------------------------------------------------------*/
 class CS;
 const int MAXHANDLE = CHAR_BIT*sizeof(int)-1;
