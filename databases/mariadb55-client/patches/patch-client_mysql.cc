$NetBSD: patch-client_mysql.cc,v 1.2 2015/05/07 12:45:29 fhajny Exp $

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
@@ -2640,7 +2640,11 @@ static void initialize_readline (char *n
   rl_completion_entry_function= &no_completion;
   rl_add_defun("magic-space", (Function*)&fake_magic_space, -1);
 #else
+# if defined(USE_READLINE_V6)
+  rl_attempted_completion_function= (rl_completion_func_t*)&new_mysql_completion;
+# else
   rl_attempted_completion_function= (CPPFunction*)&new_mysql_completion;
+# endif
   rl_completion_entry_function= &no_completion;
 #endif
 }
@@ -2657,7 +2661,7 @@ static char **new_mysql_completion(const
                                    int end __attribute__((unused)))
 {
   if (!status.batch && !quick)
-#if defined(USE_NEW_READLINE_INTERFACE)
+#if defined(USE_NEW_READLINE_INTERFACE) || defined(USE_READLINE_V6)
     return rl_completion_matches(text, new_command_generator);
 #else
     return completion_matches((char *)text, (CPFunction *)new_command_generator);
