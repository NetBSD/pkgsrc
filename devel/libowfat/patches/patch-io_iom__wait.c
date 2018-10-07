$NetBSD: patch-io_iom__wait.c,v 1.1 2018/10/07 12:13:46 schmonz Exp $

Fix build on systems with kqueue(2).

--- io/iom_wait.c.orig	2018-04-11 14:12:50.000000000 +0000
+++ io/iom_wait.c
@@ -76,13 +76,13 @@ int iom_wait(iomux_t* c,int64* s,unsigne
 #endif
 	return r;
       }
-      for (i=0; i<r; ++i) {
+      for (int i=0; i<r; ++i) {
 	/* convert events */
 	int e = (kev[i].filter == EVFILT_READ ? IOM_READ : 0) |
 	        (kev[i].filter == EVFILT_WRITE ? IOM_WRITE : 0);
 	if (i+1==r) {
 	  /* return last event instead of enqueueing it */
-	  *s=kev.ident;
+	  *s=kev[i].ident;
 	  *revents=e;
 	} else {
 	  c->q[c->h].fd=kev[i].ident;
