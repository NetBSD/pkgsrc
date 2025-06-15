$NetBSD: patch-zlib_zutil.c,v 1.1 2025/06/15 12:51:36 js Exp $

Fix building on macOS 15.

--- zlib/zutil.c.orig	2025-04-20 20:10:32.611766921 +0000
+++ zlib/zutil.c
@@ -7,2 +7,4 @@
 
+#include <stdio.h>
+
 #include "zutil.h"
