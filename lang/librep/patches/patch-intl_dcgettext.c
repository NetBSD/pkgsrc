$NetBSD: patch-intl_dcgettext.c,v 1.1 2026/10/19 23:09:37 gutteridge Exp $

Provide correct/consistent prototype for getcwd(3).

--- intl/dcgettext.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ intl/dcgettext.c
@@ -99,7 +99,7 @@ char *getwd ();
 char *getwd ();
 #  define getcwd(buf, max) getwd (buf)
 # else
-char *getcwd ();
+char *getcwd (char *, size_t);
 # endif
 # ifndef HAVE_STPCPY
 static char *stpcpy PARAMS ((char *dest, const char *src));
