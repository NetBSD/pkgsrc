$NetBSD: patch-src_sed_lib_utils.c,v 1.2 2018/01/02 10:37:29 wiz Exp $

Add missing include.

--- src/sed/lib/utils.c.orig	2017-11-26 23:30:40.000000000 +0900
+++ src/sed/lib/utils.c	2017-11-27 00:23:09.561021581 +0900
@@ -35,6 +35,8 @@
 # include <stdlib.h>
 #endif /* HAVE_STDLIB_H */
 
+#include <unistd.h>
+
 #include "utils.h"
 
 #ifdef KBUILD_OS_WINDOWS /* bird: Way faster console output! */
