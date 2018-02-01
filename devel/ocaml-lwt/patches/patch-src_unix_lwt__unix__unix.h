$NetBSD: patch-src_unix_lwt__unix__unix.h,v 1.1 2018/02/01 09:40:13 jperkin Exp $

Need limits.h for IOV_MAX.
Avoid system NANOSEC definition.

--- src/unix/lwt_unix_unix.h.orig	2017-12-19 21:28:38.000000000 +0000
+++ src/unix/lwt_unix_unix.h
@@ -33,6 +33,7 @@
 #include <caml/unixsupport.h>
 #include <caml/version.h>
 #include <dirent.h>
+#include <limits.h>
 #include <poll.h>
 #include <sys/resource.h>
 #include <sys/time.h>
@@ -1288,11 +1289,11 @@ static value copy_stat(int use_64, struc
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
