$NetBSD: patch-client_mysql.cc,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- client/mysql.cc.orig	2015-02-13 12:07:00.000000000 +0000
+++ client/mysql.cc
@@ -89,7 +89,7 @@ extern "C" {
 #if defined(__WIN__)
 #include <conio.h>
 #else
-#include <readline.h>
+#include <readline/readline.h>
 #define HAVE_READLINE
 #define USE_POPEN
 #endif
