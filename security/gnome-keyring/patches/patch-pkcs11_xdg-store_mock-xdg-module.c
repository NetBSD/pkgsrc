$NetBSD: patch-pkcs11_xdg-store_mock-xdg-module.c,v 1.1 2025/04/29 21:05:30 tnn Exp $

* Include <sys/time.h> for gettimeofday(2)

--- pkcs11/xdg-store/mock-xdg-module.c.orig	2024-08-07 11:00:54.782885957 +0000
+++ pkcs11/xdg-store/mock-xdg-module.c
@@ -37,6 +37,7 @@
 
 #include <errno.h>
 #include <sys/times.h>
+#include <sys/time.h>
 
 #include <string.h>
 
