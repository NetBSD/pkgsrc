$NetBSD: patch-client_mysql.cc,v 1.1 2015/10/07 11:22:00 adam Exp $

--- client/mysql.cc.orig	2015-10-07 10:53:49.000000000 +0000
+++ client/mysql.cc
@@ -97,7 +97,7 @@ extern "C" {
 #if defined(__WIN__)
 #include <conio.h>
 #else
-#include <readline.h>
+#include <readline/readline.h>
 #define HAVE_READLINE
 #define USE_POPEN
 #endif
