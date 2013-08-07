$NetBSD: patch-unix_uxnet.c,v 1.2 2013/08/07 11:06:39 drochner Exp $

--- unix/uxnet.c.orig	2013-07-27 18:35:48.000000000 +0000
+++ unix/uxnet.c
@@ -534,10 +534,10 @@ static int try_connect(Actual_Socket soc
 {
     int s;
     union sockaddr_union u;
-    const union sockaddr_union *sa;
+    const union sockaddr_union *sa = NULL;
     int err = 0;
     short localport;
-    int salen, family;
+    int salen = 0, family;
 
     /*
      * Remove the socket from the tree before we overwrite its
