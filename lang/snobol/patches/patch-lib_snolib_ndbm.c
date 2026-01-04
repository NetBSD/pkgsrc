$NetBSD: patch-lib_snolib_ndbm.c,v 1.1 2026/01/04 11:16:28 wiz Exp $

--- lib/snolib/ndbm.c.orig	2026-01-04 11:14:36.323854956 +0000
+++ lib/snolib/ndbm.c
@@ -44,6 +44,7 @@
 #endif /* HAVE_CONFIG_H defined */
 
 #include <fcntl.h>
+#include <stdlib.h>
 
 /* only one will be set: */
 #ifdef HAVE_NDBM_H
