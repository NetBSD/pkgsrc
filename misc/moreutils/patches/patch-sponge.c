$NetBSD: patch-sponge.c,v 1.1 2018/09/29 21:33:47 wiedi Exp $

Need MAX() on SunOS

--- sponge.c.orig	2017-12-31 16:02:11.000000000 +0000
+++ sponge.c
@@ -36,6 +36,10 @@
 #include <signal.h>
 #include <getopt.h>
 
+#if !defined(MAX)
+#define MAX(a, b) ((a) > (b) ? (a) : (b))
+#endif
+
 #include "physmem.c"
 
 #define BUFF_SIZE           8192
