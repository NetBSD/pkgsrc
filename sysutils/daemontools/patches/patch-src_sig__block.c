$NetBSD: patch-src_sig__block.c,v 1.1 2025/06/27 17:30:46 schmonz Exp $

Find sigprocmask on Illumos when in C89 mode.

--- src/sig_block.c.orig	2001-07-12 16:49:49.000000000 +0000
+++ src/sig_block.c
@@ -1,5 +1,6 @@
 /* Public domain. */
 
+#define _POSIX_C_SOURCE 1
 #include <signal.h>
 #include "sig.h"
 #include "hassgprm.h"
