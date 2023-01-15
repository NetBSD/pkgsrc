$NetBSD: patch-cpmcp.c,v 1.1 2023/01/15 15:41:47 thorpej Exp $

Some systems require <sys/types.h> before <sys/stat.h>.

--- cpmcp.c.orig	2012-10-07 10:46:25.000000000 +0000
+++ cpmcp.c
@@ -1,8 +1,8 @@
 /* #includes */ /*{{{C}}}*//*{{{*/
 #include "config.h"
 
-#include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <ctype.h>
 #include <errno.h>
 #include <stdio.h>
