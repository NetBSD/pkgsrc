$NetBSD: patch-sysunix.c,v 1.1 2013/10/24 09:35:10 jperkin Exp $

--- sysunix.c.orig	2003-10-01 09:57:29.000000000 +0000
+++ sysunix.c
@@ -21,6 +21,10 @@ its own modules. */
 #include <fcntl.h>
 #include <dirent.h>
             
+#if defined(__sun)
+# include <sys/filio.h>
+#endif
+
 #include "ehdr.h"
 #include "unixhdr.h"
 #include "scomhdr.h"
