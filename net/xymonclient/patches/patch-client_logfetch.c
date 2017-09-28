$NetBSD: patch-client_logfetch.c,v 1.1 2017/09/28 10:40:35 spz Exp $

make sure intmax_t is defined

--- client/logfetch.c.orig	2016-11-05 19:02:06.000000000 +0000
+++ client/logfetch.c
@@ -21,6 +21,9 @@ static char rcsid[] = "$Id: logfetch.c 7
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
 #include <time.h>
 #include <limits.h>
 #include <errno.h>
