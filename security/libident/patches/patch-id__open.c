$NetBSD: patch-id__open.c,v 1.1 2013/12/13 10:46:40 jperkin Exp $

Need sys/file.h for FNDELAY on SunOS.

--- id_open.c.orig	2004-01-18 17:21:28.000000000 +0000
+++ id_open.c
@@ -30,6 +30,9 @@
 # endif
 #endif
 
+#ifdef __sun
+#include <sys/file.h>
+#endif
 
 #define IN_LIBIDENT_SRC
 #include "ident.h"
