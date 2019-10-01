$NetBSD: patch-otherlibs_systhreads_st__stubs.c,v 1.2 2019/10/01 09:52:51 maya Exp $

Make the POSIX sigwait visible on SmartOS

--- otherlibs/systhreads/st_stubs.c.orig	2019-08-05 17:32:44.000000000 +0000
+++ otherlibs/systhreads/st_stubs.c
@@ -15,6 +15,9 @@
 
 #define CAML_INTERNALS
 
+/* Needed for sigwait */
+#define _POSIX_PTHREAD_SEMANTICS
+
 #include "caml/alloc.h"
 #include "caml/backtrace.h"
 #include "caml/callback.h"

