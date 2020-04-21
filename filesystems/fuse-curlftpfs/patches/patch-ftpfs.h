$NetBSD: patch-ftpfs.h,v 1.1 2020/04/21 13:56:26 nia Exp $

Include limits.h for PATH_MAX.

--- ftpfs.h.orig	2008-04-25 10:32:30.000000000 +0000
+++ ftpfs.h
@@ -12,7 +12,7 @@
 #include <curl/curl.h>
 #include <curl/easy.h>
 #include <pthread.h>
-#include <pthread.h>
+#include <limits.h>
 
 struct ftpfs {
   char* host;
