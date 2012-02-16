--- lib/syncmgr.c.orig	2005-07-08 21:25:22.000000000 +0200
+++ lib/syncmgr.c	2012-01-26 21:40:31.623129670 +0100
@@ -11,6 +11,10 @@
 #include <string.h>
 #include <sys/param.h> /* for MIN(a,b) */
 
+#ifdef __sun
+#include <sys/sysmacros.h>
+#endif
+
 #define VERBOSE 0
 
 static const char* RRA_DIRECTORY    = "rra";
