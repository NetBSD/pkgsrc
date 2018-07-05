$NetBSD: patch-goffice_math_go-math.c,v 1.1 2018/07/05 14:26:03 jperkin Exp $

SunOS needs ieeefp.h for finite().

--- goffice/math/go-math.c.orig	2018-03-07 02:16:56.000000000 +0000
+++ goffice/math/go-math.c
@@ -30,6 +30,9 @@
 #include <signal.h>
 #include <errno.h>
 #include <string.h>
+#ifdef __sun
+#include <ieeefp.h>
+#endif
 
 double go_nan;
 double go_pinf;
