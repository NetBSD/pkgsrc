$NetBSD: patch-sal_osl_unx_system.hxx,v 1.1 2019/02/19 16:28:03 ryoon Exp $

--- sal/osl/unx/system.hxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ sal/osl/unx/system.hxx
@@ -182,7 +182,6 @@
 #endif
 
 #if defined(DRAGONFLY) || defined(NETBSD)
-#   define  ETIME ETIMEDOUT
 #   include <pthread.h>
 #   include <sys/sem.h>
 #   include <dlfcn.h>
