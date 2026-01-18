$NetBSD: patch-vendor_ocaml-lmdb_lmdb__stubs.c,v 1.1 2026/01/18 21:50:46 wiz Exp $

Fix build on NetBSD.

--- vendor/ocaml-lmdb/lmdb_stubs.c.orig	2026-01-18 14:09:30.274938476 +0000
+++ vendor/ocaml-lmdb/lmdb_stubs.c
@@ -17,7 +17,7 @@
 
 #ifdef _WIN32
 #include <malloc.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 #include <stdlib.h>
 #else
 #include <alloca.h>
