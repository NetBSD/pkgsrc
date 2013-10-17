$NetBSD: patch-src_dpimp.c,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/dpimp.c.orig	2003-02-23 10:07:35.000000000 +0000
+++ src/dpimp.c
@@ -228,6 +228,10 @@ default for every OS that implements /de
 #include <sys/resource.h>	/* For setpriority() */
 #include <sys/mman.h>		/* For mlockall() */
 
+#if CENV_SYS_NETBSD
+#include <poll.h>
+#endif
+
 #include "dpimp.h"	/* DPIMP specific defs, grabs DPSUP if needed */
 
 #ifdef RCSID
