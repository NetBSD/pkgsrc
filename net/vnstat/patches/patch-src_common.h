$NetBSD: patch-src_common.h,v 1.1 2024/10/10 19:56:02 nia Exp $

Include <fcntl.h> for open(2).

--- src/common.h.orig	2024-10-10 19:54:21.793147584 +0000
+++ src/common.h
@@ -5,6 +5,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
+#include <fcntl.h>
 #include <locale.h>
 #include <time.h>
 #include <string.h>
