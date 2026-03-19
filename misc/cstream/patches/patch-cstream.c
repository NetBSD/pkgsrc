$NetBSD: patch-cstream.c,v 1.1 2026/03/19 14:52:29 nia Exp $

Fix implicit declaration of bzero(3).

--- cstream.c.orig	2026-03-19 14:39:56.374861640 +0000
+++ cstream.c
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 #include <math.h>
 #if HAVE_UNISTD_H || CRAENV
