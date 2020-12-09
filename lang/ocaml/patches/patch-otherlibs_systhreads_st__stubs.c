$NetBSD: patch-otherlibs_systhreads_st__stubs.c,v 1.4 2020/12/09 10:33:04 jaapb Exp $

Make the POSIX sigwait visible on SmartOS

--- otherlibs/systhreads/st_stubs.c.orig	2020-09-01 12:47:58.000000000 +0000
+++ otherlibs/systhreads/st_stubs.c
@@ -15,6 +15,9 @@
 
 #define CAML_INTERNALS
 
+/* Needed for sigwait */
+#define _POSIX_PTHREAD_SEMANTICS
+
 #include "caml/alloc.h"
 #include "caml/backtrace.h"
 #include "caml/callback.h"
