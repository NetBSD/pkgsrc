$NetBSD: patch-src_Bootstrap.h,v 1.2 2024/07/27 12:22:54 bacon Exp $

# Portability

--- src/Bootstrap.h.orig	2020-04-01 16:56:42 UTC
+++ src/Bootstrap.h
@@ -1,6 +1,7 @@
 #ifndef KALLISTO_BOOTSTRAP_H
 #define KALLISTO_BOOTSTRAP_H
 
+#include <sys/types.h>
 #include <mutex>
 #include <thread>
 
