$NetBSD: patch-master_defs.h,v 1.1 2014/09/11 07:15:56 dholland Exp $

- Don't rely on __unused from netbsd's <cdefs.h> existing.

--- master/defs.h~	2013-01-02 23:00:43.000000000 +0000
+++ master/defs.h
@@ -33,6 +33,10 @@
 #include <err.h>
 #include <errno.h>
 
+#ifndef __unused
+#define __unused __attribute__((__unused__))
+#endif
+
 #define SOCKADDR    struct sockaddr_in	  /* shorter to type */
 
 /*
