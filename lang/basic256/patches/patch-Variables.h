$NetBSD: patch-Variables.h,v 1.1 2015/06/12 13:12:27 joerg Exp $

--- Variables.h.orig	2015-06-09 23:15:06.000000000 +0000
+++ Variables.h
@@ -34,7 +34,7 @@ struct variable
   union {
     char *string;
     double floatval; 
-    array *arr;
+    ::array *arr;
   } value;
 };
 
