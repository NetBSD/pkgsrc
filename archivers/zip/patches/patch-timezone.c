$NetBSD: patch-timezone.c,v 1.1 2024/08/05 09:23:37 tnn Exp $

Needs <time.h> for struct tm.

--- timezone.c.orig	2024-08-05 10:58:20.252837901 +0000
+++ timezone.c
@@ -41,6 +41,7 @@
 #include "timezone.h"
 #include <ctype.h>
 #include <errno.h>
+#include <time.h>
 
 #ifdef IZTZ_DEFINESTDGLOBALS
 long timezone = 0;
