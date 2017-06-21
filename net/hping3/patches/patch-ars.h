$NetBSD: patch-ars.h,v 1.1.2.2 2017/06/21 18:20:04 bsiegert Exp $

SunOS requires alloca.h

--- ars.h.orig	2004-06-04 07:22:38.000000000 +0000
+++ ars.h
@@ -11,6 +11,9 @@
 #define _BSD_SOCKLEN_T_ int
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <string.h>
