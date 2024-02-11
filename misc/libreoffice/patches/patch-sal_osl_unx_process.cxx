$NetBSD: patch-sal_osl_unx_process.cxx,v 1.1 2024/02/11 15:31:58 ryoon Exp $

--- sal/osl/unx/process.cxx.orig	2024-02-01 12:17:10.253704607 +0000
+++ sal/osl/unx/process.cxx
@@ -26,6 +26,7 @@
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <signal.h>
 
 /*
  *   ToDo:
