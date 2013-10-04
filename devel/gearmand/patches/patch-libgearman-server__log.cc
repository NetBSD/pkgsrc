$NetBSD: patch-libgearman-server__log.cc,v 1.1 2013/10/04 07:03:37 fhajny Exp $

alloca.h is a linux-ism

--- libgearman-server/log.cc.orig	2013-05-04 09:34:54.000000000 +0000
+++ libgearman-server/log.cc
@@ -54,7 +54,7 @@
 #include <ctime>
 #include <pthread.h>
 
-#ifdef _WIN32
+#if defined(_WIN32) || defined(__NetBSD__)
 # include <malloc.h>
 #else
 # include <alloca.h>
