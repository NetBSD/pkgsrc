$NetBSD: patch-widget_look-cool.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

NetBSD doesn't have sys/sysmacros.h

--- widget/look-cool.c.orig	2026-10-20 19:19:52.493987975 +0000
+++ widget/look-cool.c
@@ -11,7 +11,7 @@
 #include <my_string.h>
 #include <stdlib.h>
 #include <stdarg.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
 #endif
 
