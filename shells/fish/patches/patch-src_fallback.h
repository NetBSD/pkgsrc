$NetBSD: patch-src_fallback.h,v 1.3 2017/10/30 11:45:14 jperkin Exp $

Work around NetBSD curses.

--- src/fallback.h.orig	2017-06-03 12:45:13.000000000 +0000
+++ src/fallback.h
@@ -37,7 +37,7 @@ int fish_mkstemp_cloexec(char *);
 /// Under curses, tputs expects an int (*func)(char) as its last parameter, but in ncurses, tputs
 /// expects a int (*func)(int) as its last parameter. tputs_arg_t is defined to always be what tputs
 /// expects. Hopefully.
-#ifdef NCURSES_VERSION
+#if defined(NCURSES_VERSION) || defined(__NetBSD__)
 typedef int tputs_arg_t;
 #else
 typedef char tputs_arg_t;
