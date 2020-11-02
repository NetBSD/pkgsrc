$NetBSD: patch-qmail-remote.c,v 1.1 2020/11/02 10:24:58 schmonz Exp $

The bundled tcpclient isn't special; use an installed one.

--- qmail-remote.c.orig	2013-04-14 10:07:50.000000000 +0000
+++ qmail-remote.c
@@ -139,7 +139,7 @@ void child(stralloc *d1, stralloc *d2, s
         run[i++] = "-c";
     }
     else {
-        run[i++] = "qmail-tcpclient";
+        run[i++] = "tcpclient";
         run[i++] = "-T";
         run[i++] = strtimeout;
         run[i++] = "-HDRl0";
