$NetBSD: patch-nowutc.c,v 1.1 2026/03/17 14:58:30 nia Exp $

ANSIfy.

--- nowutc.c.orig	2026-03-17 14:46:08.956924034 +0000
+++ nowutc.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include "leapsecs.h"
 #include "tai.h"
 #include "taia.h"
@@ -10,6 +11,7 @@ struct caltime ct;
 
 char x[TAIA_FMTFRAC];
 
+int
 main()
 {
   if (leapsecs_init() == -1) {
