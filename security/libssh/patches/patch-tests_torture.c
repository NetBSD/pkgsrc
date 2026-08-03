$NetBSD: patch-tests_torture.c,v 1.3 2026/08/03 19:42:41 wiz Exp $

Fix build on NetBSD 8.1: Don't try to use PATH_MAX without #include <limits.h>

--- tests/torture.c.orig	2026-07-16 10:48:05.000000000 +0000
+++ tests/torture.c
@@ -24,6 +24,7 @@
 #include "config.h"
 #include "tests_config.h"
 #include <fcntl.h>
+#include <limits.h>
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
