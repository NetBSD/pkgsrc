$NetBSD: patch-test-getconfopt.c,v 1.1 2017/05/25 20:41:27 schmonz Exp $

Fix Illumos build.

--- test-getconfopt.c.orig	2014-05-15 02:54:21.000000000 +0000
+++ test-getconfopt.c
@@ -1,6 +1,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include "fmt.h"
+#include "sgetopt.h"
 #include "getconfopt.h"
 #include "stralloc.h"
 #include "substdio.h"
