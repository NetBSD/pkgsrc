$NetBSD: patch-lib_strings__mosq.c,v 1.2 2022/08/16 23:08:39 gdt Exp $

Suppress warning by including missing header.

--- lib/strings_mosq.c.orig	2022-08-16 13:34:02.000000000 +0000
+++ lib/strings_mosq.c
@@ -21,6 +21,10 @@ Contributors:
 #include <errno.h>
 #include <string.h>
 
+#if defined(__NetBSD__)
+#include <strings.h>
+#endif
+
 #ifndef WIN32
 #  include <strings.h>
 #endif
