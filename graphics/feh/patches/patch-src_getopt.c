$NetBSD: patch-src_getopt.c,v 1.3 2020/11/23 13:10:54 nia Exp $

Include string.h for strlen().

--- src/getopt.c.orig	2020-08-29 06:50:28.000000000 +0000
+++ src/getopt.c
@@ -97,6 +97,7 @@
    they can distinguish the relative order of options and other arguments.  */
 
 #include "getopt.h"
+#include <string.h>
 
 /* For communication from `getopt' to the caller.
    When `getopt' finds an option that takes an argument,
