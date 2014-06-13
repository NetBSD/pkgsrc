$NetBSD: patch-src_connection.c,v 1.1 2014/06/13 00:13:13 wiedi Exp $

NetBSD doesn't have alloca.h
--- src/connection.c.orig	2014-05-18 21:52:06.000000000 +0000
+++ src/connection.c
@@ -39,7 +39,9 @@
 #include <arpa/inet.h>
 #include <ev.h>
 #include <assert.h>
+#if !defined(__NetBSD__)
 #include <alloca.h>
+#endif
 #include "connection.h"
 #include "resolv.h"
 #include "address.h"
