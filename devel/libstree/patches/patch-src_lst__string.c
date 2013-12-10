$NetBSD: patch-src_lst__string.c,v 1.1 2013/12/10 12:01:15 jperkin Exp $

Provide compat MIN()

--- src/lst_string.c.orig	2004-01-13 14:14:26.000000000 +0000
+++ src/lst_string.c
@@ -26,6 +26,10 @@ CONNECTION WITH THE SOFTWARE OR THE USE
 #  include <config.h>
 #endif
 
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
 #include <sys/param.h>
 
 #include "lst_string.h"
