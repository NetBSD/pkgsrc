$NetBSD: patch-os_netbsd.cpp,v 1.1 2017/12/15 11:38:26 hauke Exp $

Missing #include

--- os_netbsd.cpp.orig	2017-08-08 19:38:15.000000000 +0000
+++ os_netbsd.cpp
@@ -26,6 +26,7 @@
 
 #include <sys/drvctlio.h>
 #include <sys/utsname.h>
+#include <sys/stat.h>
 #include <errno.h>
 #include <unistd.h>
 
