$NetBSD: patch-src_xitk_network.c,v 1.1 2022/04/10 16:49:15 nia Exp $

Include correct readline headers on NetBSD
(fails with editline).

--- src/xitk/network.c.orig	2021-12-12 19:49:29.000000000 +0000
+++ src/xitk/network.c
@@ -63,8 +63,8 @@
 #include <netdb.h>
 #include <pthread.h>
 
-#include <readline.h>
-#include <history.h>
+#include <readline/readline.h>
+#include <readline/history.h>
 
 #include "common.h"
 #include "network.h"
