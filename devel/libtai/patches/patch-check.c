$NetBSD: patch-check.c,v 1.1 2026/03/17 14:58:30 nia Exp $

ANSIfy.

--- check.c.orig	2026-03-17 14:48:54.718452452 +0000
+++ check.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include <time.h>
 #include "tai.h"
 #include "leapsecs.h"
@@ -11,6 +12,7 @@ char *dayname[7] = { "Sun", "Mon", "Tue"
 char out[101];
 char x[TAI_PACK];
 
+int
 main()
 {
   struct tai t;
