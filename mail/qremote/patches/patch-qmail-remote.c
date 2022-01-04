$NetBSD: patch-qmail-remote.c,v 1.2 2022/01/04 21:03:22 schmonz Exp $

The bundled tcpclient, curvecpclient, and curvecpmessage aren't special.
Use whatever's installed.

--- qmail-remote.c.orig	2013-04-14 10:07:50.000000000 +0000
+++ qmail-remote.c
@@ -124,7 +124,7 @@ void child(stralloc *d1, stralloc *d2, s
 
     i = 0;
     if (ix->haskey) {
-        run[i++] = "qmail-curvecpclient";
+        run[i++] = "curvecpclient";
         if (flagkeydir) {
             run[i++] = "-c";
             run[i++] = keydir.s;
@@ -135,11 +135,11 @@ void child(stralloc *d1, stralloc *d2, s
         run[i++] = ipstr;
         run[i++] = strport;
         run[i++] = ix->ext;
-        run[i++] = "qmail-curvecpmessage";
+        run[i++] = "curvecpmessage";
         run[i++] = "-c";
     }
     else {
-        run[i++] = "qmail-tcpclient";
+        run[i++] = "tcpclient";
         run[i++] = "-T";
         run[i++] = strtimeout;
         run[i++] = "-HDRl0";
