$NetBSD: patch-core-junction.c,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Portability

--- core-junction.c.orig	2018-11-08 15:19:02 UTC
+++ core-junction.c
@@ -22,6 +22,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <assert.h>
+#include <unistd.h>
 #include "subread.h"
 #include "sublog.h"
 #include "gene-value-index.h"
