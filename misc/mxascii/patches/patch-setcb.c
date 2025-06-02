$NetBSD: patch-setcb.c,v 1.1 2025/06/02 07:45:16 vins Exp $

Fix signedness mismatch warning.

--- setcb.c.orig	2025-06-02 07:29:00.090325109 +0000
+++ setcb.c
@@ -197,7 +197,7 @@ void SetCb (Widget widget,XtPointer clie
     static int
         first_time=0;
 
-    type=(int) client_data;
+    type=(long) client_data;
 
     if (first_time == 0)
     {
