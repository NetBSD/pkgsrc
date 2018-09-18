$NetBSD: patch-ext_posix_sys_socket.c,v 1.1 2018/09/18 03:37:03 maya Exp $

Missing include. Committed upstream:
https://github.com/luaposix/luaposix/commit/29c1eb56c32c84c87835201c4dd9c0883521b8d8

--- ext/posix/sys/socket.c.orig	2018-02-21 02:29:31.000000000 +0000
+++ ext/posix/sys/socket.c
@@ -36,6 +36,7 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <netinet/udp.h>
+#include <sys/time.h>
 #include <sys/un.h>
 
 
