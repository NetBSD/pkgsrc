$NetBSD: patch-dc_input.c,v 1.1 2025/07/02 02:59:05 markd Exp $

<string.h> for strlen()

--- dc/input.c.orig	2024-12-28 00:59:14.000000000 +0000
+++ dc/input.c
@@ -22,6 +22,7 @@
 #include "../config.h"
 #include <stdio.h>
 #include <stdlib.h> /* free, getenv */
+#include <string.h>
 #include "dc.h"
 
 static const char *PROMPT = NULL; //NULL => prior to first-readline
