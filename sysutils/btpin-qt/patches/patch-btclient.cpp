$NetBSD: patch-btclient.cpp,v 1.1 2013/05/06 15:04:55 joerg Exp $

--- btclient.cpp.orig	2013-05-04 14:26:39.000000000 +0000
+++ btclient.cpp
@@ -26,6 +26,7 @@
 #include <sys/cdefs.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#include <unistd.h>
 
 #include <bluetooth.h>
 #include <err.h>
