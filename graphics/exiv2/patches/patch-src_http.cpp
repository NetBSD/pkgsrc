$NetBSD: patch-src_http.cpp,v 1.1.2.2 2015/10/06 17:44:21 spz Exp $

Include <errno.h> rather than <sys/errno.h> because the latter doesn't
actually make `errno` available on NetBSD; while the former is required
to by the C standard


--- src/http.cpp.orig	2015-10-02 05:47:47.000000000 +0200
+++ src/http.cpp	2015-10-02 05:47:52.000000000 +0200
@@ -70,7 +70,7 @@
 
 #include <unistd.h>
 #include <strings.h>
-#include <sys/errno.h>
+#include <errno.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/uio.h>
