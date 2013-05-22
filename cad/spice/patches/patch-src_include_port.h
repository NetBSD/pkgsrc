$NetBSD: patch-src_include_port.h,v 1.1 2013/05/22 07:44:04 sbd Exp $

--- src/include/port.h.orig	1993-04-14 19:51:11.000000000 +0000
+++ src/include/port.h
@@ -16,6 +16,11 @@ Copyright 1990 Regents of the University
 #  define CONFIGURED
 #endif
 
+#ifdef linux
+#  include "os_linux.h"
+#  define CONFIGURED
+#endif
+
 #ifdef ultrix
 #  include "os_ultrx.h"
 #  define CONFIGURED
