$NetBSD: patch-unix_uxnet.c,v 1.1.2.2 2012/02/23 15:53:57 tron Exp $

--- unix/uxnet.c.orig	2009-08-06 22:55:15.000000000 +0000
+++ unix/uxnet.c
@@ -526,10 +526,10 @@ static int try_connect(Actual_Socket soc
 {
     int s;
     union sockaddr_union u;
-    const union sockaddr_union *sa;
+    const union sockaddr_union *sa = NULL;
     int err = 0;
     short localport;
-    int fl, salen, family;
+    int fl, salen = 0, family;
 
     /*
      * Remove the socket from the tree before we overwrite its
