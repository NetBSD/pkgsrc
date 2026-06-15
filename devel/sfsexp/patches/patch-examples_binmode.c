$NetBSD: patch-examples_binmode.c,v 1.1 2026/06/15 07:22:00 nia Exp $

Include the standard open(2) header, should help building on SunOS
with GCC 15.

--- examples/binmode.c.orig	2026-06-15 07:17:53.390539746 +0000
+++ examples/binmode.c
@@ -31,10 +31,10 @@ LA-CC-04-094
 
 **/
 
-#include <sys/fcntl.h>
 #include "sexp.h"
 #include <assert.h>
 #ifndef WIN32
+# include <fcntl.h>
 # include <unistd.h>
 #else
 # define ssize_t int
