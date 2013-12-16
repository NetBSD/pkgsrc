$NetBSD: patch-master_utmp.c,v 1.1 2013/12/16 06:42:20 dholland Exp $

Fix build failure when NO_WHO is defined.

--- master/utmp.c~	2013-01-02 02:07:17.000000000 +0000
+++ master/utmp.c
@@ -69,9 +69,11 @@ findtty(const char *user, const char *tt
 void
 who(struct sockaddr_in *sin)
 {
+#ifndef NO_WHO
     struct  utmpx *utmp;
     int     users = 0;
     char   *msg = NULL;
+#endif
 
 #ifdef NO_WHO       /* not allowed here ... */
     sendit(misc, sin, "%c%c%cwho@%s: this site doesn't allow remote who.", 
