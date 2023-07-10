$NetBSD: patch-client_mysql.cc,v 1.1 2023/07/10 22:55:49 nia Exp $

Do not special case __APPLE__ for pkgsrc builds.

--- client/mysql.cc.orig	2023-06-05 17:14:07.000000000 +0000
+++ client/mysql.cc
@@ -89,14 +89,10 @@ extern "C" {
 
 #undef bcmp				// Fix problem with new readline
 #if !defined(_WIN32)
-# ifdef __APPLE__
-#  include <editline/readline.h>
-# else
 #  include <readline.h>
 #  if !defined(USE_LIBEDIT_INTERFACE)
 #   include <history.h>
 #  endif
-# endif
 #define HAVE_READLINE
 #endif
 #define USE_POPEN
