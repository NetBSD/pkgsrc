$NetBSD: patch-write__afm.c,v 1.1 2025/12/22 23:22:02 wiz Exp $

Add missing header for strcmp().

--- write_afm.c.orig	2025-12-22 23:20:36.763159800 +0000
+++ write_afm.c
@@ -24,6 +24,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <limits.h>
 #include <time.h>
 #include <ftxpost.h>
