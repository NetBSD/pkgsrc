$NetBSD: patch-src_rktio_rktio__network.c,v 1.1 2018/07/24 12:22:07 jaapb Exp $

Need to include sys/time.h
--- src/rktio/rktio_network.c.orig	2017-10-12 18:23:27.000000000 +0000
+++ src/rktio/rktio_network.c
@@ -12,6 +12,7 @@
 # include <netinet/in.h>
 # include <netdb.h>
 # include <sys/socket.h>
+# include <sys/time.h>
 # include <sys/types.h>
 # include <fcntl.h>
 # include <errno.h>
