$NetBSD: patch-client_mysql.cc,v 1.1 2022/04/06 18:04:51 brook Exp $

Do not special case __APPLE__ for pkgsrc builds.

--- client/mysql.cc.orig	2022-02-10 20:17:07.000000000 +0000
+++ client/mysql.cc
@@ -91,14 +91,10 @@ extern "C" {
 #if defined(_WIN32)
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
