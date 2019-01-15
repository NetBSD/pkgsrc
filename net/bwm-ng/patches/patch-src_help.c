$NetBSD: patch-src_help.c,v 1.1 2019/01/15 09:28:25 wiz Exp $

Remove inline to fix build with clang.

--- src/help.c.orig	2015-07-07 18:50:25.000000000 +0000
+++ src/help.c
@@ -24,9 +24,9 @@
 #include "global_vars.h"
 #include "help.h"
 
-inline void print_help_line(const char *short_c,const char * long_c,const char *descr);
+void print_help_line(const char *short_c,const char * long_c,const char *descr);
 
-inline void print_help_line(const char *short_c,const char * long_c,const char *descr) {
+void print_help_line(const char *short_c,const char * long_c,const char *descr) {
 #ifdef LONG_OPTIONS
     printf("  %-23s",long_c);
 #else
