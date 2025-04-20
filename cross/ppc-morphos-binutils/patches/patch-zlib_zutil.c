$NetBSD: patch-zlib_zutil.c,v 1.1 2025/04/20 10:57:39 js Exp $

Fix building on macOS 15.

--- zlib/zutil.c.orig	2025-04-20 10:46:50.421260348 +0000
+++ zlib/zutil.c
@@ -7,2 +7,4 @@
 
+#include <stdio.h>
+
 #include "zutil.h"
