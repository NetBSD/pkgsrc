$NetBSD: patch-window.h,v 1.2 2021/02/12 22:29:37 cjep Exp $

OpenBSD grumbles without the socket definitions

--- window.h.orig	Wed Feb  5 20:09:38 2020
+++ window.h	Thu Feb 11 21:01:43 2021
@@ -33,6 +33,10 @@
 #ifndef SCREEN_WINDOW_H
 #define SCREEN_WINDOW_H
 
+#ifdef _OpenBSD_
+#include <sys/socket.h>
+#endif
+
 /* keep this in sync with the initialisations in window.c */
 struct NewWindow
 {
