$NetBSD: patch-timers.c,v 1.1 2021/12/16 14:23:55 wiz Exp $

Remove incorrect check.

--- timers.c.orig	2017-12-19 04:44:21.000000000 +0000
+++ timers.c
@@ -32,10 +32,6 @@ hpTimerUnit(void)
 
 #else  /* !MS_WINDOWS */
 
-#ifndef HAVE_GETTIMEOFDAY
-#error "This module requires gettimeofday() on non-Windows platforms!"
-#endif
-
 #if (defined(PYOS_OS2) && defined(PYCC_GCC))
 #include <sys/time.h>
 #else
