$NetBSD: patch-src_callback.c,v 1.1 2026/06/18 16:07:13 nia Exp $

Avoid implicit declaration of exit(3).

--- src/callback.c.orig	2003-04-24 00:21:29.000000000 +0000
+++ src/callback.c
@@ -24,6 +24,7 @@
 #include "user_config.h"
 #include "os.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include "xstuff.h"
 #include "callback.h"
 #include "common.h"
