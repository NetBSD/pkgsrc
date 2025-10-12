$NetBSD: patch-metamail_mmencode.c,v 1.1 2025/10/12 00:57:39 mrg Exp $

- Add types for GCC 14.

--- metamail/mmencode.c.orig	1994-01-26 10:47:37.000000000 -0800
+++ metamail/mmencode.c	2025-10-11 16:52:59.027033250 -0700
@@ -13,14 +13,18 @@ OF THIS MATERIAL FOR ANY PURPOSE.  IT IS
 WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES.
 */
 #include <stdio.h>
+#include <stdlib.h>
 #include <config.h>
 #ifdef MSDOS
 #include <fcntl.h>
 #endif
 
+#include "metamail.h"
+
 #define BASE64 1
 #define QP 2 /* quoted-printable */
 
+int
 main(argc, argv)
 int argc;
 char **argv;
