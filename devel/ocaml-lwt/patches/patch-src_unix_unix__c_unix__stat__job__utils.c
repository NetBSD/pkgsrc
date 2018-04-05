$NetBSD: patch-src_unix_unix__c_unix__stat__job__utils.c,v 1.1 2018/04/05 11:04:40 jaapb Exp $

Need limits.h for IOV_MAX.
Avoid system NANOSEC definition.

--- src/unix/unix_c/unix_stat_job_utils.c.orig	2018-01-11 16:40:12.000000000 +0000
+++ src/unix/unix_c/unix_stat_job_utils.c
@@ -28,6 +28,7 @@
 #include <caml/alloc.h>
 #include <caml/memory.h>
 #include <errno.h>
+#include <limits.h>
 
 #include "unix_stat_job_utils.h"
 
@@ -37,11 +38,11 @@ value copy_stat(int use_64, struct stat 
     CAMLlocal5(atime, mtime, ctime, offset, v);
 
     atime = caml_copy_double((double)buf->st_atime +
-                             (NANOSEC(buf, a) / 1000000000.0));
+                             (OCNANOSEC(buf, a) / 1000000000.0));
     mtime = caml_copy_double((double)buf->st_mtime +
-                             (NANOSEC(buf, m) / 1000000000.0));
+                             (OCNANOSEC(buf, m) / 1000000000.0));
     ctime = caml_copy_double((double)buf->st_ctime +
-                             (NANOSEC(buf, c) / 1000000000.0));
+                             (OCNANOSEC(buf, c) / 1000000000.0));
     offset = use_64 ? caml_copy_int64(buf->st_size) : Val_int(buf->st_size);
     v = caml_alloc_small(12, 0);
     Field(v, 0) = Val_int(buf->st_dev);
