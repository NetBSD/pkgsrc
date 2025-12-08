$NetBSD: patch-misc.h,v 1.1 2025/12/08 21:05:41 vins Exp $

Otherwise HelpTextOutput() is undeclared. 

--- misc.h.orig	2025-12-08 20:47:27.811755189 +0000
+++ misc.h
@@ -104,7 +104,7 @@ extern XColor *DoGrabColor(Widget w);
 /* help.c */
 extern char *matchGet(char *line, char *pat);
 extern void HelpDialog(Widget parent, String name);
-#if defined( _STDIO_H ) || defined( __VMS ) 
+#if defined( HAVE_STDIO_H ) || defined( __VMS ) 
 extern void HelpTextOutput(FILE* fd, String name);
 #endif
 extern void HelpInit(Widget top);
