$NetBSD: patch-bpgdec.c,v 1.1 2026/03/18 10:06:40 nia Exp $

Fix implicit declarations of string functions.

--- bpgdec.c.orig	2026-03-18 09:44:51.203135555 +0000
+++ bpgdec.c
@@ -26,6 +26,8 @@
 #include <stdio.h>
 #include <math.h>
 #include <getopt.h>
+#include <string.h>
+#include <strings.h>
 #include <inttypes.h>
 
 /* define it to include PNG output */
