$NetBSD: patch-io_iom__init.c,v 1.1 2019/12/22 22:23:00 joerg Exp $

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
