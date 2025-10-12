$NetBSD: patch-inc_toast.h,v 1.1 2025/10/12 04:07:04 mrg Exp $

Don't define _POSIX_C_SOURCE on NetBSD to avoid hiding fchmod(2).


--- inc/toast.h.orig	2022-07-31 09:16:42.711313021 -0700
+++ inc/toast.h	2025-10-11 20:50:31.193859647 -0700
@@ -11,9 +11,11 @@
 
 #include "config.h"
 
+#ifndef __NetBSD__
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 200809L
 #endif
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
