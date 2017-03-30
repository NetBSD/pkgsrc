--- extras/mini-os/lib//sys.c.orig	2017-03-28 13:14:26.000000000 +0200
+++ extras/mini-os/lib//sys.c	2017-03-28 13:14:39.000000000 +0200
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
 #include <console.h>
