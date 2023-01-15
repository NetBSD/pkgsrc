$NetBSD: patch-cpmfs.c,v 1.1 2023/01/15 15:41:47 thorpej Exp $

Some systems require <sys/types.h> before <sys/stat.h>.

--- cpmfs.c.orig	2012-10-07 10:46:25.000000000 +0000
+++ cpmfs.c
@@ -1,6 +1,7 @@
 /* #includes */ /*{{{C}}}*//*{{{*/
 #include "config.h"
 
+#include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
 #include <ctype.h>
