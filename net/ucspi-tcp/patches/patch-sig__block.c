$NetBSD: patch-sig__block.c,v 1.1 2025/06/27 17:18:18 schmonz Exp $

Find sigprocmask on Illumos when in C89 mode.

--- sig_block.c.orig	2025-06-25 17:37:49.223374819 +0000
+++ sig_block.c
@@ -1,3 +1,4 @@
+#define _POSIX_C_SOURCE 1
 #include <signal.h>
 #include "sig.h"
 #include "hassgprm.h"
