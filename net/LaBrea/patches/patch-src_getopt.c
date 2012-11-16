$NetBSD: patch-src_getopt.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/getopt.c.orig	2003-09-09 20:55:03.000000000 +0000
+++ src/getopt.c
@@ -105,7 +105,7 @@
    GNU application programs can use a third alternative mode in which
    they can distinguish the relative order of options and other arguments.  */
 
-#include "getopt.h"
+#include "../inc/getopt.h"
 
 /* For communication from `getopt' to the caller.
    When `getopt' finds an option that takes an argument,
