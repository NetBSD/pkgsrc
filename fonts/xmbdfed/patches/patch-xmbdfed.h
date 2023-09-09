$NetBSD: patch-xmbdfed.h,v 1.1 2023/09/09 14:56:28 vins Exp $

Variable already declared as static.

--- xmbdfed.h.orig	2001-11-09 14:01:52.000000000 -0800
+++ xmbdfed.h
@@ -258,7 +258,6 @@ extern Widget top, questd, errd, saved, 
 extern XtAppContext app;
 extern Boolean yes_no_answer;
 extern Boolean yes_no_done;
-extern unsigned long active_editor;
 extern String app_name;
 extern String app_class;
 extern char title[];
