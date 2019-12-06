$NetBSD: patch-src_libopts_makeshell.c,v 1.3 2019/12/06 14:00:08 nia Exp $

Avoid stdnoreturn.h.

--- src/libopts/makeshell.c.orig	2019-12-01 21:25:38.000000000 +0000
+++ src/libopts/makeshell.c
@@ -35,7 +35,7 @@
 #define UPPER(_c) (toupper(to_uchar(_c)))
 #define LOWER(_c) (tolower(to_uchar(_c)))
 
-noreturn static void
+static void
 option_exits(int exit_code)
 {
     if (print_exit)
@@ -43,7 +43,7 @@ option_exits(int exit_code)
     exit(exit_code);
 }
 
-noreturn static void
+static void
 ao_bug(char const * msg)
 {
     fprintf(stderr, zao_bug_msg, msg);
@@ -57,7 +57,7 @@ fserr_warn(char const * prog, char const
             op, fname);
 }
 
-noreturn static void
+static void
 fserr_exit(char const * prog, char const * op, char const * fname)
 {
     fserr_warn(prog, op, fname);
