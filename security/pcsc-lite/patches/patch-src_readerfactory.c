$NetBSD: patch-src_readerfactory.c,v 1.1 2025/10/17 13:19:44 jperkin Exp $

SunOS needs alloca.h.

--- src/readerfactory.c.orig	2025-10-17 13:17:57.013766183 +0000
+++ src/readerfactory.c
@@ -40,6 +40,9 @@ THIS SOFTWARE, EVEN IF ADVISED OF THE PO
  */
 
 #include "config.h"
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
