$NetBSD: patch-ars.h,v 1.1 2017/06/14 12:17:30 jperkin Exp $

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
