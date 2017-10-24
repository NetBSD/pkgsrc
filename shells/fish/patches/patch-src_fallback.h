$NetBSD: patch-src_fallback.h,v 1.1 2017/10/24 03:51:41 maya Exp $

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
@@ -57,7 +57,7 @@ struct winsize {
 #ifdef TPARM_SOLARIS_KLUDGE
 /// Solaris tparm has a set fixed of paramters in it's curses implementation, work around this here.
 #define tparm tparm_solaris_kludge
-char *tparm_solaris_kludge(char *str, ...);
+char *tparm_solaris_kludge(const char *str, ...);
 #endif
 
 /// On OS X, use weak linking for wcsdup and wcscasecmp. Weak linking allows you to call the
