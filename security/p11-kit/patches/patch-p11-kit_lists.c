$NetBSD: patch-p11-kit_lists.c,v 1.1.2.2 2021/01/27 19:40:46 spz Exp $

Add missing header for SIZE_MAX on FreeBSD.
https://github.com/p11-glue/p11-kit/commit/507c394

--- p11-kit/lists.c.orig	2021-01-08 21:05:52.577818000 +0100
+++ p11-kit/lists.c
@@ -39,6 +39,7 @@
 
 #include <assert.h>
 #include <ctype.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
