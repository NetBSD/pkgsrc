$NetBSD: patch-vendor_ocaml-lmdb_mdb.c,v 1.1 2026/01/18 21:50:46 wiz Exp $

Fix build on NetBSD.

--- vendor/ocaml-lmdb/mdb.c.orig	2026-01-18 14:12:57.789992548 +0000
+++ vendor/ocaml-lmdb/mdb.c
@@ -38,6 +38,9 @@
 #if defined(MDB_VL32) || defined(__WIN64__)
 #define _FILE_OFFSET_BITS	64
 #endif
+#if defined(__NetBSD__)
+#define _SEM_SEMUN_UNDEFINED 1
+#endif
 #ifdef _WIN32
 #include <malloc.h>
 #include <windows.h>
