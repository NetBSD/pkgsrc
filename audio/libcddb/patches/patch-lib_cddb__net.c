$NetBSD: patch-lib_cddb__net.c,v 1.1 2014/01/09 13:05:20 wiz Exp $

Use correct type to fix this on big-endian hosts.

From Dave Tyson on pkgsrc-users 20140108,
"libcddb fails to work properly on big-endian systems"

http://mail-index.netbsd.org/pkgsrc-users/2014/01/08/msg019154.html

--- lib/cddb_net.c.orig	2009-03-01 03:28:07.000000000 +0000
+++ lib/cddb_net.c
@@ -305,7 +305,7 @@ int timeout_connect(int sockfd, const st
             int rv;
             fd_set wfds;
             struct timeval tv;
-            size_t l;
+            socklen_t l;
 
             /* set up select time out */
             tv.tv_sec = timeout;
