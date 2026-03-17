$NetBSD: patch-leapsecs.c,v 1.1 2026/03/17 14:58:30 nia Exp $

ANSIfy.

--- leapsecs.c.orig	2026-03-17 14:45:27.142514914 +0000
+++ leapsecs.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include "tai.h"
 #include "leapsecs.h"
 #include "caldate.h"
@@ -9,6 +10,7 @@
 
 char line[100];
 
+int
 main()
 {
   struct caldate cd;
