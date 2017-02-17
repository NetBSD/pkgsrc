$NetBSD: patch-kismet__wrapper.cc,v 1.1 2017/02/17 17:10:05 joerg Exp $

--- kismet_wrapper.cc.orig	2017-02-17 13:54:47.534806189 +0000
+++ kismet_wrapper.cc
@@ -24,6 +24,7 @@
 #include <vector>
 #include <errno.h>
 #include <sys/wait.h>
+#include <sys/time.h>
 #include <fcntl.h>
 #include <unistd.h>
 
