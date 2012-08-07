$NetBSD: patch-src_main_security.c,v 1.1 2012/08/07 16:06:06 ryoon Exp $

* Fix include order

--- src/main/security.c.orig	2012-03-07 06:52:15.000000000 +0000
+++ src/main/security.c
@@ -27,6 +27,9 @@
 
 /* ************************************************************************ */
 
+#include <sys/param.h>
+#include <sys/sysctl.h>
+
 #include"commons.h"
 
 #ifdef K_USING_WIN32_
