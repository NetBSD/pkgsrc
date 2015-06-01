$NetBSD: patch-src_libopts_makeshell.c,v 1.2 2015/06/01 21:50:22 spz Exp $

Avoid stdnoreturn.h.

--- src/libopts/makeshell.c.orig	2015-03-23 07:19:23.000000000 +0000
+++ src/libopts/makeshell.c
@@ -68,7 +68,7 @@ static void
 open_out(char const * fname, char const * pname);
 /* = = = END-STATIC-FORWARD = = = */
 
-LOCAL noreturn void
+LOCAL void
 option_exits(int exit_code)
 {
     if (print_exit)
@@ -76,7 +76,7 @@ option_exits(int exit_code)
     exit(exit_code);
 }
 
-LOCAL noreturn void
+LOCAL void
 ao_bug(char const * msg)
 {
     fprintf(stderr, zao_bug_msg, msg);
@@ -90,7 +90,7 @@ fserr_warn(char const * prog, char const
             op, fname);
 }
 
-LOCAL noreturn void
+LOCAL void
 fserr_exit(char const * prog, char const * op, char const * fname)
 {
     fserr_warn(prog, op, fname);
