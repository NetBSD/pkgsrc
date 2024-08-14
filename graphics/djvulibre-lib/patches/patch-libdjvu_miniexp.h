$NetBSD: patch-libdjvu_miniexp.h,v 1.1 2024/08/14 06:14:56 adam Exp $

Avoid double declaration.

--- libdjvu/miniexp.h.orig	2006-05-12 16:23:36.000000000 +0000
+++ libdjvu/miniexp.h
@@ -46,7 +46,9 @@ extern "C" { 
    information */
 
 
-typedef struct miniexp_s* miniexp_t;
+#ifndef DDJVUAPI
+typedef struct miniexp_s* miniexp_t; 
+#endif
 
 
 /* There are four basic types of lisp expressions,
