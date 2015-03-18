$NetBSD: patch-fallback.h,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- fallback.h.orig	2015-03-17 21:45:59.000000000 +0000
+++ fallback.h
@@ -43,7 +43,7 @@ int fish_wcswidth(const wchar_t *str, si
    expects. Hopefully.
 */
 
-#ifdef NCURSES_VERSION
+#if defined(__NetBSD__) || defined(NCURSES_VERSION)
 typedef int tputs_arg_t;
 #else
 typedef char tputs_arg_t;
@@ -86,7 +86,10 @@ int tputs(const char *str, int affcnt, i
 
 #endif
 
-#ifdef TPARM_SOLARIS_KLUDGE
+#ifdef __NetBSD__
+#include <term.h>
+#define tparm tiparm
+#elif defined(TPARM_SOLARIS_KLUDGE)
 
 /**
    Solaris tparm has a set fixed of paramters in it's curses implementation,
