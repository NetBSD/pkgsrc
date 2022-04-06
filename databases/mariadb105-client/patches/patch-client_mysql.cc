$NetBSD: patch-client_mysql.cc,v 1.1 2022/04/06 18:16:13 brook Exp $

Do not special case __APPLE__ for pkgsrc builds.

--- client/mysql.cc.orig	2022-02-10 20:11:29.000000000 +0000
+++ client/mysql.cc
@@ -91,14 +91,10 @@ extern "C" {
 #if defined(__WIN__)
 #include <conio.h>
 #else
-# ifdef __APPLE__
-#  include <editline/readline.h>
-# else
-#  include <readline.h>
-#  if !defined(USE_LIBEDIT_INTERFACE)
-#   include <history.h>
-#  endif
-# endif
+#include <readline.h>
+#if !defined(USE_LIBEDIT_INTERFACE)
+# include <history.h>
+#endif
 #define HAVE_READLINE
 #endif
 #define USE_POPEN
