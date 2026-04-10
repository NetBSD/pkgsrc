$NetBSD: patch-gnulib-tests_localename.c,v 1.1 2026/04/10 09:50:52 jperkin Exp $

Fix broken gnulib.

--- gnulib-tests/localename.c.orig	2026-04-10 09:48:53.607376483 +0000
+++ gnulib-tests/localename.c
@@ -44,8 +44,6 @@
 # include "glthread/lock.h"
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
-/* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
