$NetBSD: patch-mandocdb.c,v 1.7 2015/12/10 02:50:19 joerg Exp $

--- mandocdb.c.orig	2015-12-07 15:20:09.513956486 +0000
+++ mandocdb.c
@@ -30,7 +30,6 @@
 #else
 #include "compat_fts.h"
 #endif
-#include <getopt.h>
 #include <limits.h>
 #include <stddef.h>
 #include <stdio.h>
