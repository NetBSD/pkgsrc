$NetBSD: patch-internal.h,v 1.1 2024/10/10 20:33:39 nia Exp $

Include <limits.h> for LONG_MIN/LONG_MAX.

--- internal.h.orig	2024-10-10 20:30:50.817453129 +0000
+++ internal.h
@@ -203,6 +203,7 @@ typedef unsigned short sa_family_t;
 #include <signal.h>
 #include <fcntl.h>
 #include <ctype.h>
+#include <limits.h>
 #include <time.h>
 #include <math.h>
 
