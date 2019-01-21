$NetBSD: patch-iodev_network_slirp_slirp.h,v 1.1 2019/01/21 10:04:45 markd Exp $

uintptr_t not declared on linux without this

--- iodev/network/slirp/slirp.h.orig	2014-12-25 17:58:26.557466000 +0000
+++ iodev/network/slirp/slirp.h
@@ -33,7 +33,7 @@ typedef char *caddr_t;
 #endif
 
 #include <sys/types.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__linux__)
 #include <stdint.h>
 #include <sys/wait.h>
 #endif
