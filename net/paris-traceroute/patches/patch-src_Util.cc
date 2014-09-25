$NetBSD: patch-src_Util.cc,v 1.1 2014/09/25 16:08:24 jperkin Exp $

SunOS needs strings.h for bzero().

--- src/Util.cc.orig	2007-06-06 09:21:19.000000000 +0000
+++ src/Util.cc
@@ -5,6 +5,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef __sun
+#include <strings.h>
+#endif
 #include <unistd.h>
 //#include <asm/types.h>
 #include <sys/ioctl.h>
