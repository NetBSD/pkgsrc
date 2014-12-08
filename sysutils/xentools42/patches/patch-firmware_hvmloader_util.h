--- firmware/hvmloader/util.h.orig	2014-09-02 15:22:57.000000000 +0900
+++ firmware/hvmloader/util.h	2014-12-08 13:01:39.000000000 +0900
@@ -3,6 +3,7 @@
 
 #include <stdarg.h>
 #include <stdint.h>
+#include <stddef.h>
 #include <xen/xen.h>
 #include <xen/hvm/hvm_info_table.h>
 
@@ -172,7 +173,6 @@
 int vprintf(const char *fmt, va_list ap);
 
 /* Buffer output */
-typedef unsigned long size_t;
 int snprintf(char *buf, size_t size, const char *fmt, ...) __attribute__ ((format (printf, 3, 4)));
 
 /* Populate specified memory hole with RAM. */
