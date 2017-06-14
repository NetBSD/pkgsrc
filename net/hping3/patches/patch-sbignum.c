$NetBSD: patch-sbignum.c,v 1.1 2017/06/14 12:17:30 jperkin Exp $

SunOS requires alloca.h

--- sbignum.c.orig	2003-10-02 08:21:42.000000000 +0000
+++ sbignum.c
@@ -40,6 +40,9 @@
  * 12 Sep 2003: Fixed a memory leak in mpz_tostr().
  */
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
