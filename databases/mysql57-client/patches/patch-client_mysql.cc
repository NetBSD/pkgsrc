$NetBSD: patch-client_mysql.cc,v 1.1 2020/05/07 05:31:53 adam Exp $

Editline fixes.

--- client/mysql.cc.orig	2020-05-06 16:48:02.000000000 +0000
+++ client/mysql.cc
@@ -2828,7 +2828,7 @@ static int fake_magic_space(int, int);
 char *no_completion(const char *, int)
 #elif defined(USE_LIBEDIT_INTERFACE)
 static int fake_magic_space(int, int);
-char *no_completion(const char *, int)
+int no_completion(const char *, int)
 #else
 char *no_completion()
 #endif
@@ -2855,7 +2855,7 @@ static int not_in_history(const char *li
 #if defined(USE_NEW_EDITLINE_INTERFACE)
 static int fake_magic_space(int, int)
 #else
-static int fake_magic_space(int, int)
+static int fake_magic_space(const char *, int)
 #endif
 {
   rl_insert(1, ' ');
