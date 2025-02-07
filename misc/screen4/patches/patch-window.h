$NetBSD: patch-window.h,v 1.1 2025/02/07 03:15:06 ryoon Exp $

OpenBSD grumbles without the socket definitions

--- window.h.orig	Wed Feb  5 20:09:38 2020
+++ window.h	Thu Feb 11 21:27:43 2021
@@ -33,6 +33,10 @@
 #ifndef SCREEN_WINDOW_H
 #define SCREEN_WINDOW_H
 
+#ifdef __OpenBSD__
+#include <sys/socket.h>
+#endif
+
 /* keep this in sync with the initialisations in window.c */
 struct NewWindow
 {
