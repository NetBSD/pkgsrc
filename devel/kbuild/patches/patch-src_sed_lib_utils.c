$NetBSD: patch-src_sed_lib_utils.c,v 1.1 2016/07/08 09:42:54 kamil Exp $

Add missing include.

--- src/sed/lib/utils.c.orig	2015-06-21 21:21:26.000000000 +0000
+++ src/sed/lib/utils.c
@@ -35,6 +35,8 @@
 # include <stdlib.h>
 #endif /* HAVE_STDLIB_H */
 
+#include <unistd.h>
+
 #include "utils.h"
 
 const char *myname;
