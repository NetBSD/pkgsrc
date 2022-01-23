$NetBSD: patch-io_iom__init.c,v 1.2 2022/01/23 13:30:33 schmonz Exp $

Fix build on systems with kqueue(2).

--- io/iom_init.c.orig	2019-12-22 18:12:04.396371533 +0000
+++ io/iom_init.c
@@ -6,6 +6,8 @@
 #include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
+#include <sys/fcntl.h>
+#include <unistd.h>
 #endif
 
 int iom_init(iomux_t* c) {
