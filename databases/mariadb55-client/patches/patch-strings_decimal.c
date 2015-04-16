$NetBSD: patch-strings_decimal.c,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Portability: include <bstring.h> if exists.

--- strings/decimal.c.orig	2015-02-13 12:07:15.000000000 +0000
+++ strings/decimal.c
@@ -103,6 +103,9 @@
 #include <myisampack.h>
 #include <my_sys.h> /* for my_alloca */
 #include <decimal.h>
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
 
 /*
   Internally decimal numbers are stored base 10^9 (see DIG_BASE below)
