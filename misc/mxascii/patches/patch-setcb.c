$NetBSD: patch-setcb.c,v 1.2 2025/06/02 11:23:11 vins Exp $

Fix size mismatch warning.

--- setcb.c.orig	2025-06-02 07:29:00.090325109 +0000
+++ setcb.c
@@ -197,7 +197,7 @@ void SetCb (Widget widget,XtPointer clie
     static int
         first_time=0;
 
-    type=(int) client_data;
+    type=(long) client_data;
 
     if (first_time == 0)
     {
