$NetBSD: patch-client_mysql.cc,v 1.3 2017/02/03 16:20:18 roy Exp $

--- client/mysql.cc.orig	2016-09-12 14:54:54.000000000 +0000
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
@@ -2634,20 +2634,20 @@ static void initialize_readline (char *n
   rl_readline_name = name;
 
   /* Tell the completer that we want a crack first. */
-#if defined(USE_NEW_READLINE_INTERFACE)
+#if defined(USE_NEW_READLINE_INTERFACE) || defined(USE_LIBEDIT_INTERFACE)
+#if defined(USE_LIBEDIT_INTERFACE) && defined(HAVE_LOCALE_H)
+  setlocale(LC_ALL,""); /* so as libedit use isprint */
+#endif
   rl_attempted_completion_function= (rl_completion_func_t*)&new_mysql_completion;
   rl_completion_entry_function= (rl_compentry_func_t*)&no_completion;
 
   rl_add_defun("magic-space", (rl_command_func_t *)&fake_magic_space, -1);
-#elif defined(USE_LIBEDIT_INTERFACE)
-#ifdef HAVE_LOCALE_H
-  setlocale(LC_ALL,""); /* so as libedit use isprint */
-#endif
-  rl_attempted_completion_function= (CPPFunction*)&new_mysql_completion;
-  rl_completion_entry_function= &no_completion;
-  rl_add_defun("magic-space", (Function*)&fake_magic_space, -1);
 #else
+# if defined(USE_READLINE_V6)
+  rl_attempted_completion_function= (rl_completion_func_t*)&new_mysql_completion;
+# else
   rl_attempted_completion_function= (CPPFunction*)&new_mysql_completion;
+# endif
   rl_completion_entry_function= &no_completion;
 #endif
 }
@@ -2664,7 +2664,7 @@ static char **new_mysql_completion(const
                                    int end __attribute__((unused)))
 {
   if (!status.batch && !quick)
-#if defined(USE_NEW_READLINE_INTERFACE)
+#if defined(USE_NEW_READLINE_INTERFACE) || defined(USE_LIBEDIT_INTERFACE) || defined(USE_READLINE_V6)
     return rl_completion_matches(text, new_command_generator);
 #else
     return completion_matches((char *)text, (CPFunction *)new_command_generator);
