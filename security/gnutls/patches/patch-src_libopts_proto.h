$NetBSD: patch-src_libopts_proto.h,v 1.3 2019/12/06 14:00:08 nia Exp $

Avoid stdnoreturn.h.

--- src/libopts/proto.h.orig	2019-12-01 21:25:38.000000000 +0000
+++ src/libopts/proto.h
@@ -247,16 +247,16 @@ load_opt_line(tOptions * opts, tOptState
 /*
  * Static declarations from makeshell.c
  */
-noreturn static void
+static void
 option_exits(int exit_code);
 
-noreturn static void
+static void
 ao_bug(char const * msg);
 
 static void
 fserr_warn(char const * prog, char const * op, char const * fname);
 
-noreturn static void
+static void
 fserr_exit(char const * prog, char const * op, char const * fname);
 
 static void
