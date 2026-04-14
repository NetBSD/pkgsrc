$NetBSD: patch-src_basic_memfd-util.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* F_ADD_SEALS available since NetBSD-11

--- src/basic/memfd-util.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/memfd-util.c
@@ -7,9 +7,10 @@
 
 #include "alloc-util.h"
 #include "memfd-util.h"
+#include "missing.h"
 
 int memfd_set_sealed(int fd) {
-#if defined(__FreeBSD__) && __FreeBSD__ < 13
+#if defined(__FreeBSD__) && __FreeBSD__ < 13 || (defined(__NetBSD__) && __NetBSD__ < 11)
         return 0;
 #else
         int r;
