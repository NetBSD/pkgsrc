$NetBSD: patch-libgearman_backtrace.cc,v 1.1 2013/10/10 00:04:52 joerg Exp $

--- libgearman/backtrace.cc.orig	2013-10-09 23:42:25.000000000 +0000
+++ libgearman/backtrace.cc
@@ -67,14 +67,14 @@ void custom_backtrace(void)
 #ifdef HAVE_EXECINFO_H
   void *backtrace_buffer[MAX_DEPTH +1];
 
-  int stack_frames= backtrace(backtrace_buffer, MAX_DEPTH);
-  fprintf(stderr, "\nBegin stack trace, frames found: %d\n", stack_frames);
+  size_t stack_frames= backtrace(backtrace_buffer, MAX_DEPTH);
+  fprintf(stderr, "\nBegin stack trace, frames found: %zu\n", stack_frames);
   if (stack_frames)
   {
     char **symbollist= backtrace_symbols(backtrace_buffer, stack_frames);
     if (symbollist)
     {
-      for (int x= 0; x < stack_frames; x++) 
+      for (size_t x= 0; x < stack_frames; x++) 
       {
         bool was_demangled= false;
 
@@ -102,7 +102,7 @@ void custom_backtrace(void)
               }
 
               was_demangled= true;
-              fprintf(stderr, "#%d  %p in %s at %s\n",
+              fprintf(stderr, "#%zu  %p in %s at %s\n",
                       x, backtrace_buffer[x],
                       called_in,
                       dlinfo.dli_fname);
@@ -113,7 +113,7 @@ void custom_backtrace(void)
 
         if (was_demangled == false)
         {
-          fprintf(stderr, "?%d  %p in %s\n", x, backtrace_buffer[x], symbollist[x]);
+          fprintf(stderr, "?%zu  %p in %s\n", x, backtrace_buffer[x], symbollist[x]);
         }
       }
 
