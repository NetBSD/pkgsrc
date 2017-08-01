$NetBSD: patch-desktop_unx_source_pagein.c,v 1.1 2017/08/01 11:57:37 ryoon Exp $

--- desktop/unx/source/pagein.c.orig	2017-07-25 20:26:39.000000000 +0000
+++ desktop/unx/source/pagein.c
@@ -25,7 +25,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
+#if !defined(__NetBSD__)
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 
 /* do_pagein */
