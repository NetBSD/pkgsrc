$NetBSD: patch-conserver_util.c,v 1.1 2017/09/11 14:59:45 hauke Exp $

Built with gcc 5.4 on netbsd-8, conserver terminates because of a
buffer overflow in StrTime(), when it tries to stuff a 25 char string
into a 25 byte buffer.

--- conserver/util.c.orig	2003-04-06 12:29:48.000000000 +0000
+++ conserver/util.c
@@ -77,7 +77,7 @@ StrTime(ltime)
     time_t *ltime;
 #endif
 {
-    static char curtime[25];
+    static char curtime[63];
     time_t tyme;
 
     tyme = time((time_t *) 0);
