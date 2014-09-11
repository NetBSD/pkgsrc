$NetBSD: patch-conv_convd.c,v 1.1 2014/09/11 07:15:56 dholland Exp $

- Don't rely on __unused from netbsd's <cdefs.h> existing.

--- conv/convd.c~	2013-01-02 23:00:43.000000000 +0000
+++ conv/convd.c
@@ -48,6 +48,10 @@
 
 #include "../common.h"
 
+#ifndef __unused
+#define __unused __attribute__((__unused__))
+#endif
+
 #ifndef lint
 #if 0
 static char __unused char RCSid[] = "Header: convd.c,v 1.1 85/10/29 14:20:06 broome Exp ";
