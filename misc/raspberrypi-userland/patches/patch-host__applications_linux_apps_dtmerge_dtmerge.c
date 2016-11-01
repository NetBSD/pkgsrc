$NetBSD: patch-host__applications_linux_apps_dtmerge_dtmerge.c,v 1.1 2016/11/01 16:45:28 skrll Exp $

--- host_applications/linux/apps/dtmerge/dtmerge.c.orig	2016-11-01 11:24:50.000000000 +0000
+++ host_applications/linux/apps/dtmerge/dtmerge.c
@@ -26,6 +26,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 */
 
 #include <stdio.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <libfdt.h>
 
