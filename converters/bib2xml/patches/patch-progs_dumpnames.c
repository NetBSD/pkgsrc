$NetBSD: patch-progs_dumpnames.c,v 1.1 2025/11/26 08:30:25 wiz Exp $

Add missing headers.

--- progs/dumpnames.c.orig	2025-11-26 08:26:21.079765277 +0000
+++ progs/dumpnames.c
@@ -15,6 +15,8 @@
 -------------------------------------------------------------------------- */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "btparse.h"
 
 char *Usage = "usage: dumpnames file\n";
