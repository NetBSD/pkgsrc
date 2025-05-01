$NetBSD: patch-gnu_getopt.c,v 1.1 2025/05/01 16:58:48 tnn Exp $

* Include <string.h> for strlen(3)

--- gnu/getopt.c.orig	2025-05-01 16:57:05.278129342 +0000
+++ gnu/getopt.c
@@ -40,6 +40,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
