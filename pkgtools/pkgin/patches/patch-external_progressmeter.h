$NetBSD: patch-external_progressmeter.h,v 1.1 2015/03/25 02:10:02 rodent Exp $

Including sys/termios.h on FreeBSD throws a warning and breaks the build.

--- external/progressmeter.h.orig	2015-03-08 17:49:37.000000000 +0000
+++ external/progressmeter.h
@@ -26,7 +26,7 @@
 
 #include "config.h"
 
-#ifdef HAVE_SYS_TERMIOS_H
+#if defined(HAVE_SYS_TERMIOS_H) && !defined(__FreeBSD__)
 #include <sys/termios.h>
 #elif HAVE_TERMIOS_H
 #include <termios.h>
