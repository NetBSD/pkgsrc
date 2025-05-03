$NetBSD: patch-zlib_zutil.c,v 1.1 2025/05/03 16:19:25 tnn Exp $

Fix building on macOS 15.

--- zlib/zutil.c.orig	2025-05-03 16:07:20.137783431 +0000
+++ zlib/zutil.c
@@ -7,2 +7,4 @@
 
+#include <stdio.h>
+
 #include "zutil.h"
