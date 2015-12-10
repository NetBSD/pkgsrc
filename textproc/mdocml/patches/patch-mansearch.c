$NetBSD: patch-mansearch.c,v 1.1 2015/12/10 02:50:19 joerg Exp $

--- mansearch.c.orig	2015-12-07 15:20:30.565955584 +0000
+++ mansearch.c
@@ -23,7 +23,6 @@
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <getopt.h>
 #include <glob.h>
 #include <limits.h>
 #include <regex.h>
