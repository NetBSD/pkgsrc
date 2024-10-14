$NetBSD: patch-config.h,v 1.2 2024/10/14 21:27:44 gdt Exp $

Visibility define exorcism.  Resolves failure to see initgroups prototype
(correctly) hidden by NetBSD's /usr/include.

Reported upstream by email 20241013.

--- config.h.orig
+++ config.h
@@ -7,8 +7,6 @@
 #ifdef __APPLE__
 #  define __DARWIN_C_SOURCE
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__SYMBIAN32__)
-#  define _XOPEN_SOURCE 700
-#  define __BSD_VISIBLE 1
 #  define HAVE_NETINET_IN_H
 #elif defined(__QNX__)
 #  define _XOPEN_SOURCE 600
