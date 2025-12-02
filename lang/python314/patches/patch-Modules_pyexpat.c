$NetBSD: patch-Modules_pyexpat.c,v 1.1 2025/12/02 21:34:38 adam Exp $

expat_config.h doesn't seem to be needed, and isn't available on NetBSD.

--- Modules/pyexpat.c.orig	2025-12-02 21:21:13.592360356 +0000
+++ Modules/pyexpat.c
@@ -10,7 +10,6 @@
 #include <stdbool.h>
 #include <stddef.h>               // offsetof()
 
-#include "expat_config.h"
 #include "expat.h"
 #include "pyexpat.h"
 
