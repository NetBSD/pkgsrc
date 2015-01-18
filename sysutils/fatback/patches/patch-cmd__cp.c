$NetBSD: patch-cmd__cp.c,v 1.1 2015/01/18 19:53:27 wiedi Exp $

Make sure NAME_MAX is defined.
Anything not too small should be ok, only used in a sanity check.
--- cmd_cp.c.orig	2001-05-30 15:40:00.000000000 +0000
+++ cmd_cp.c
@@ -14,6 +14,10 @@
 #include "recovery.h"
 #include "output.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 static struct option long_opts[] =
 {
      {"deleted", 0, 0, 'd'},
