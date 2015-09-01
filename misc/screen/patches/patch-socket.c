$NetBSD: patch-socket.c,v 1.2 2015/09/01 13:34:47 kim Exp $

--- socket.c.orig	2015-06-28 21:22:56.000000000 +0000
+++ socket.c	2015-09-01 12:42:34.000000000 +0000
@@ -32,9 +32,7 @@
 #include <fcntl.h>
 #if !defined(NAMEDPIPE)
 # include <sys/socket.h>
-# ifdef _OpenBSD_
-#  include <sys/uio.h>
-# endif
+# include <sys/uio.h>
 # include <sys/un.h>
 #endif
 
