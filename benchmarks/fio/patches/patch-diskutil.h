$NetBSD: patch-diskutil.h,v 1.1 2020/04/30 09:42:27 jperkin Exp $

Include limits.h for PATH_MAX.

--- diskutil.h.orig	2020-03-12 17:12:50.000000000 +0000
+++ diskutil.h
@@ -2,6 +2,7 @@
 #define FIO_DISKUTIL_H
 #define FIO_DU_NAME_SZ		64
 
+#include <limits.h>
 #include "helper_thread.h"
 #include "fio_sem.h"
 
