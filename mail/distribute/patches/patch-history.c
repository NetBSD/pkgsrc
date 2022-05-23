$NetBSD: patch-history.c,v 1.1 2022/05/23 03:55:50 dholland Exp $

Use standard headers.

--- history.c~	2022-05-23 03:43:34.271366357 +0000
+++ history.c
@@ -22,6 +22,7 @@
 #include <sysexits.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 
 #include "memory.h"
