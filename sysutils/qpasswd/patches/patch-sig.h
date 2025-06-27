$NetBSD: patch-sig.h,v 1.1 2025/06/27 17:42:58 schmonz Exp $

Avoid "storage size of ‘sa’ isn’t known" on Illumos when in C99 mode.

--- sig.h.orig	2025-06-27 01:21:46.526581732 +0000
+++ sig.h
@@ -1,6 +1,7 @@
 #ifndef QP_SIG_H
 #define QP_SIG_H
 
+#define _POSIX_SOURCE
 #include <sys/types.h>
 #include <signal.h>
 
