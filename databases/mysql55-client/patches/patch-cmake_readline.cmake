$NetBSD: patch-cmake_readline.cmake,v 1.1 2013/08/22 12:28:08 ryoon Exp $

* Fix cmake's check build error. Borrowed from mysql56's readline.cmake.

--- cmake/readline.cmake.orig	2013-06-19 15:26:27.000000000 +0000
+++ cmake/readline.cmake
@@ -156,8 +156,11 @@ MACRO (MYSQL_FIND_SYSTEM_READLINE name)
     #include <readline/readline.h>
     int main(int argc, char **argv)
     {
-      char res= *(*rl_completion_entry_function)(0,0);
+      typedef int MYFunction(const char*, int);
+      MYFunction* myf= rl_completion_entry_function;
+      int res= (myf)(NULL, 0);
       completion_matches(0,0);
+      return res;
     }"
     ${name}_USE_LIBEDIT_INTERFACE)
 
