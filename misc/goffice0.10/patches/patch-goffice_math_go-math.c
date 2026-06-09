$NetBSD: patch-goffice_math_go-math.c,v 1.2 2026/06/09 17:35:16 wiz Exp $

SunOS needs ieeefp.h for finite().

--- goffice/math/go-math.c.orig	2026-04-30 00:44:54.000000000 +0000
+++ goffice/math/go-math.c
@@ -30,6 +30,9 @@
 #include <signal.h>
 #include <errno.h>
 #include <string.h>
+#ifdef __sun
+#include <ieeefp.h>
+#endif
 
 // We need multiple versions of this code.  We're going to include ourself
 // with different settings of various macros.  gdb will hate us.
