$NetBSD: patch-src_acc__user.h,v 1.1 2020/03/18 17:45:25 joerg Exp $

--- src/acc_user.h.orig	2020-03-18 16:17:15.862134072 +0000
+++ src/acc_user.h
@@ -30,10 +30,12 @@
 
 typedef int *handle;
 
+#ifndef __cplusplus
 #define bool int
 #define true 1
-#define TRUE 1
 #define false 0
+#endif
+#define TRUE 1
 #define FALSE 0
 
 #define global extern
@@ -41,7 +43,7 @@ typedef int *handle;
 #define local static
 #define null 0L
 
-extern bool acc_error_flag;
+extern int acc_error_flag;
 
 
 /**********************************************************************/
