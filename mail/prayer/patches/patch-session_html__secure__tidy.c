$NetBSD: patch-session_html__secure__tidy.c,v 1.1 2017/02/20 09:35:17 wiz Exp $

tidy-5.x compatibility.

--- session/html_secure_tidy.c.orig	2011-06-17 14:25:54.000000000 +0000
+++ session/html_secure_tidy.c
@@ -12,7 +12,7 @@
 #include <tidy.h>
 #endif
 
-#include <buffio.h>
+#include <tidybuffio.h>
 
 /* ====================================================================== */
 
