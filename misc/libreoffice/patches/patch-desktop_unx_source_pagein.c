$NetBSD: patch-desktop_unx_source_pagein.c,v 1.2 2018/08/18 00:11:32 ryoon Exp $

--- desktop/unx/source/pagein.c.orig	2018-08-02 19:54:54.000000000 +0000
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
