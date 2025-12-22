$NetBSD: patch-write__t42.c,v 1.1 2025/12/22 23:22:02 wiz Exp $

Add missing header for strcmp().

--- write_t42.c.orig	2025-12-22 23:20:20.695179043 +0000
+++ write_t42.c
@@ -24,6 +24,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <time.h>
 #include <ftxpost.h>
 
