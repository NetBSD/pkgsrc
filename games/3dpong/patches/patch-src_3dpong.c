$NetBSD: patch-src_3dpong.c,v 1.1 2021/12/30 00:26:21 nia Exp $

unistd.h needed for usleep().

--- src/3dpong.c.orig	2004-04-29 06:49:13.000000000 +0000
+++ src/3dpong.c
@@ -15,6 +15,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <math.h>
+#include <unistd.h>
 #include "window.h"
 #include "connect.h"
 #include "hints.h"
