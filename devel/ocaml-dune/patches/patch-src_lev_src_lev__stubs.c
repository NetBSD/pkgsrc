$NetBSD: patch-src_lev_src_lev__stubs.c,v 1.1 2026/05/10 12:14:49 wiz Exp $

Add missing header (WIFEXITED etc.).
https://github.com/ocaml/dune/issues/14484

--- src/lev/src/lev_stubs.c.orig	2026-05-10 12:10:14.160997135 +0000
+++ src/lev/src/lev_stubs.c
@@ -4,7 +4,7 @@
 #include <stdint.h>
 
 #include <math.h>
-#if (defined(__FreeBSD__) || defined(__OpenBSD__))
+#if (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))
 #include <sys/wait.h>
 #endif
 #define TAG_WEXITED 0
