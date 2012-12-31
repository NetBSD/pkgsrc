$NetBSD: patch-vinagre_pty__open.c,v 1.2 2012/12/31 23:36:47 ryoon Exp $

--- vinagre/pty_open.c.orig	2011-12-03 07:23:20.000000000 +0000
+++ vinagre/pty_open.c
@@ -40,7 +40,7 @@
 
 /* Originally from vte */
 
-#define _XOPEN_SOURCE
+#define _XOPEN_SOURCE 600
 #define _GNU_SOURCE
 
 #include "config.h"
@@ -69,7 +69,7 @@
 #ifdef HAVE_UTMP_H
 #include <utmp.h>
 #endif
-#ifdef HAVE_UTIL_H
+#if defined(HAVE_LOGIN_TTY) && !defined(__linux)
 #include <util.h>
 #endif
 #include <glib.h>
