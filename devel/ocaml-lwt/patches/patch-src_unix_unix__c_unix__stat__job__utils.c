$NetBSD: patch-src_unix_unix__c_unix__stat__job__utils.c,v 1.2 2020/04/21 11:29:59 jaapb Exp $

Need limits.h for IOV_MAX.

--- src/unix/unix_c/unix_stat_job_utils.c.orig	2020-03-09 04:17:06.000000000 +0000
+++ src/unix/unix_c/unix_stat_job_utils.c
@@ -10,6 +10,7 @@
 #include <caml/alloc.h>
 #include <caml/memory.h>
 #include <errno.h>
+#include <limits.h>
 
 #include "unix_stat_job_utils.h"
 
