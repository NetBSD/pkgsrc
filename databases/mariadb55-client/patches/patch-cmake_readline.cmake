$NetBSD: patch-cmake_readline.cmake,v 1.3 2017/02/03 16:20:18 roy Exp $

--- cmake/readline.cmake.orig	2016-09-12 14:54:54.000000000 +0000
+++ cmake/readline.cmake
@@ -180,8 +180,11 @@ MACRO (MYSQL_FIND_SYSTEM_LIBEDIT)
     #include <readline.h>
     int main(int argc, char **argv)
     {
-      int res= (*rl_completion_entry_function)(0,0);
+      typedef char * MYFunction(const char*, int);
+      MYFunction* myf= rl_completion_entry_function;
+      char * res= (myf)(NULL, 0);
       completion_matches(0,0);
+      return 0;
     }"
     LIBEDIT_INTERFACE)
     SET(USE_LIBEDIT_INTERFACE ${LIBEDIT_INTERFACE})
