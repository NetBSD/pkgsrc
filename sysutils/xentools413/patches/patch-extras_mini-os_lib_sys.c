$NetBSD: patch-extras_mini-os_lib_sys.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $


--- extras/mini-os/lib/sys.c.orig	2017-10-20 12:50:35.000000000 +0200
+++ extras/mini-os/lib/sys.c	2018-04-23 15:28:25.000000000 +0200
@@ -18,6 +18,12 @@
 #define DEBUG(fmt,...)
 #endif
 
+void __enable_execute_stack (void *);
+void
+__enable_execute_stack (void *addr __attribute__((__unused__)))
+{
+}
+
 #ifdef HAVE_LIBC
 #include <os.h>
 #include <string.h>
