$NetBSD: patch-external_getopt.c,v 1.1 2012/10/20 22:08:32 joerg Exp $

--- external/getopt.c.orig	2003-01-21 21:19:37.000000000 +0000
+++ external/getopt.c
@@ -72,11 +72,9 @@
 # include <unistd.h>
 #endif	/* GNU C library.  */
 
+#include <string.h>
 #ifdef VMS
 # include <unixlib.h>
-# if HAVE_STRING_H - 0
-#  include <string.h>
-# endif
 #endif
 
 #ifndef _
