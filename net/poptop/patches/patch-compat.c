$NetBSD: patch-compat.c,v 1.1 2026/03/21 09:45:31 nia Exp $

Need to include <string.h> unconditionally since this uses strcpy(3)
and memset(3).

Need to include <unistd.h> for close(2).

--- compat.c.orig	2005-08-22 00:48:34.000000000 +0000
+++ compat.c
@@ -11,9 +11,10 @@
 #endif
 
 #include "compat.h"
+#include <string.h>
+#include <unistd.h>
 
 #ifndef HAVE_STRLCPY
-#include <string.h>
 #include <stdio.h>
 
 void strlcpy(char *dst, const char *src, size_t size)
