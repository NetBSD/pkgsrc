$NetBSD: patch-gettext-tools_gnulib-lib_localename-unsafe.c,v 1.1 2026/04/09 08:50:04 jperkin Exp $

Remove bogus forward declaration.

--- gettext-tools/gnulib-lib/localename-unsafe.c.orig	2026-04-09 08:38:01.897115586 +0000
+++ gettext-tools/gnulib-lib/localename-unsafe.c
@@ -47,8 +47,6 @@
 # endif
 # if defined __sun
 #  if HAVE_GETLOCALENAME_L
-/* Solaris >= 12.  */
-extern char * getlocalename_l(int, locale_t);
 #  elif HAVE_SOLARIS114_LOCALES
 #   include <sys/localedef.h>
 #  endif
