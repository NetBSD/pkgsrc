$NetBSD: patch-io_iom__wait.c,v 1.2 2019/12/22 22:23:00 joerg Exp $

Fix build on systems with kqueue(2).

--- io/iom_wait.c.orig	2018-04-11 14:12:50.000000000 +0000
+++ io/iom_wait.c
@@ -65,7 +65,7 @@ int iom_wait(iomux_t* c,int64* s,unsigne
 #elif defined(HAVE_KQUEUE)
       struct kevent kev[SLOTS];
       struct timespec ts = { .tv_sec=timeout/1000, .tv_nsec=(timeout%1000)*1000000 };
-      int r=kevent(c->ctx, 0, 0, &kev, freeslots, &ts);
+      int r=kevent(c->ctx, 0, 0, kev, freeslots, &ts);
       if (r<=0) {
 	/* we ran into a timeout, so let someone else take over */
 	if (__sync_val_compare_and_swap(&c->working,1,0)==-2) return -2;
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
