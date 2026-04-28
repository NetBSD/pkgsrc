$NetBSD: patch-src_osdep_unix_tcp__unix.c,v 1.1 2026/04/28 19:35:39 vins Exp $

Use poll(2) instead of select(2) to support more than 1024 file
descriptors. See https://bugs.debian.org/478193. 

--- src/osdep/unix/tcp_unix.c.orig	2011-07-23 00:20:11.000000000 +0000
+++ src/osdep/unix/tcp_unix.c
@@ -26,6 +26,7 @@
  * Last Edited:	13 January 2008
  */
 
+#include <poll.h>
 #include "ip_unix.c"
 
 #undef write			/* don't use redefined write() */
@@ -235,12 +236,11 @@ TCPSTREAM *tcp_open (char *host,char *se
 int tcp_socket_open (int family,void *adr,size_t adrlen,unsigned short port,
 		     char *tmp,int *ctr,char *hst)
 {
-  int i,ti,sock,flgs;
+  int i,ti,sock,flgs,tmo;
+  struct pollfd pfd;
   size_t len;
   time_t now;
   struct protoent *pt = getprotobyname ("tcp");
-  fd_set rfds,wfds,efds;
-  struct timeval tmo;
   struct sockaddr *sadr = ip_sockaddr (family,adr,adrlen,port,&len);
   blocknotify_t bn = (blocknotify_t) mail_parameters (NIL,GET_BLOCKNOTIFY,NIL);
 				/* fetid Solaris */
@@ -252,14 +252,6 @@ int tcp_socket_open (int family,void *ad
     sprintf (tmp,"Unable to create TCP socket: %s",strerror (errno));
     (*bn) (BLOCK_NONSENSITIVE,data);
   }
-  else if (sock >= FD_SETSIZE) {/* unselectable sockets are useless */
-    sprintf (tmp,"Unable to create selectable TCP socket (%d >= %d)",
-	     sock,FD_SETSIZE);
-    (*bn) (BLOCK_NONSENSITIVE,data);
-    close (sock);
-    sock = -1;
-    errno = EMFILE;
-  }
 
   else {			/* get current socket flags */
     flgs = fcntl (sock,F_GETFL,0);
@@ -284,16 +276,11 @@ int tcp_socket_open (int family,void *ad
     if ((sock >= 0) && ctr) {	/* want open timeout? */
       now = time (0);		/* open timeout */
       ti = ttmo_open ? now + ttmo_open : 0;
-      tmo.tv_usec = 0;
-      FD_ZERO (&rfds);		/* initialize selection vector */
-      FD_ZERO (&wfds);		/* initialize selection vector */
-      FD_ZERO (&efds);		/* handle errors too */
-      FD_SET (sock,&rfds);	/* block for error or readable or writable */
-      FD_SET (sock,&wfds);
-      FD_SET (sock,&efds);
+      pfd.fd = sock;
+      pfd.events = POLLIN | POLLOUT;
       do {			/* block under timeout */
-	tmo.tv_sec = ti ? ti - now : 0;
-	i = select (sock+1,&rfds,&wfds,&efds,ti ? &tmo : NIL);
+	tmo = ti ? ti - now : 0;
+	i = poll (&pfd, 1, ti ? tmo * 1000 : -1);
 	now = time (0);		/* fake timeout if interrupt & time expired */
 	if ((i < 0) && (errno == EINTR) && ti && (ti <= now)) i = 0;
       } while ((i < 0) && (errno == EINTR));
@@ -302,7 +289,7 @@ int tcp_socket_open (int family,void *ad
 	fcntl (sock,F_SETFL,flgs);
 	/* This used to be a zero-byte read(), but that crashes Solaris */
 				/* get socket status */
-	if(FD_ISSET(sock, &rfds)) while (((i = *ctr = read (sock,tmp,1)) < 0) && (errno == EINTR));
+	if(pfd.revents & POLLIN) while (((i = *ctr = read (sock,tmp,1)) < 0) && (errno == EINTR));
       }	
       if (i <= 0) {		/* timeout or error? */
 	i = i ? errno : ETIMEDOUT;/* determine error code */
@@ -545,9 +532,8 @@ long tcp_getbuffer (TCPSTREAM *stream,un
     stream->ictr -=n;
   }
   if (size) {
-    int i;
-    fd_set fds,efds;
-    struct timeval tmo;
+    int i, tmo;
+    struct pollfd pfd;
     time_t t = time (0);
     blocknotify_t bn=(blocknotify_t) mail_parameters (NIL,GET_BLOCKNOTIFY,NIL);
     (*bn) (BLOCK_TCPREAD,NIL);
@@ -556,16 +542,13 @@ long tcp_getbuffer (TCPSTREAM *stream,un
       time_t now = tl;
       time_t ti = ttmo_read ? now + ttmo_read : 0;
       if (tcpdebug) mm_log ("Reading TCP buffer",TCPDEBUG);
-      tmo.tv_usec = 0;
-      FD_ZERO (&fds);		/* initialize selection vector */
-      FD_ZERO (&efds);		/* handle errors too */
-				/* set bit in selection vectors */
-      FD_SET (stream->tcpsi,&fds);
-      FD_SET (stream->tcpsi,&efds);
+
+      pfd.events = POLLIN;
+      pfd.fd = stream->tcpsi;
       errno = NIL;		/* initially no error */
       do {			/* block under timeout */
-	tmo.tv_sec = ti ? ti - now : 0;
-	i = select (stream->tcpsi+1,&fds,NIL,&efds,ti ? &tmo : NIL);
+	tmo = ti ? ti - now : 0;
+	i = poll (&pfd, 1, ti ? tmo * 1000 : -1);
 	now = time (0);		/* fake timeout if interrupt & time expired */
 	if ((i < 0) && (errno == EINTR) && ti && (ti <= now)) i = 0;
       } while ((i < 0) && (errno == EINTR));
@@ -605,9 +588,8 @@ long tcp_getbuffer (TCPSTREAM *stream,un
 
 long tcp_getdata (TCPSTREAM *stream)
 {
-  int i;
-  fd_set fds,efds;
-  struct timeval tmo;
+  int i, tmo;
+  struct pollfd pfd;
   time_t t = time (0);
   blocknotify_t bn = (blocknotify_t) mail_parameters (NIL,GET_BLOCKNOTIFY,NIL);
   if (stream->tcpsi < 0) return NIL;
@@ -617,15 +599,12 @@ long tcp_getdata (TCPSTREAM *stream)
     time_t now = tl;
     time_t ti = ttmo_read ? now + ttmo_read : 0;
     if (tcpdebug) mm_log ("Reading TCP data",TCPDEBUG);
-    tmo.tv_usec = 0;
-    FD_ZERO (&fds);		/* initialize selection vector */
-    FD_ZERO (&efds);		/* handle errors too */
-    FD_SET (stream->tcpsi,&fds);/* set bit in selection vectors */
-    FD_SET (stream->tcpsi,&efds);
+    pfd.fd = stream->tcpsi;
+    pfd.events = POLLIN;
     errno = NIL;		/* initially no error */
     do {			/* block under timeout */
-      tmo.tv_sec = ti ? ti - now : 0;
-      i = select (stream->tcpsi+1,&fds,NIL,&efds,ti ? &tmo : NIL);
+      tmo = ti ? ti - now : 0;
+      i = poll (&pfd, 1, ti ? tmo * 1000 : -1);
       now = time (0);		/* fake timeout if interrupt & time expired */
       if ((i < 0) && (errno == EINTR) && ti && (ti <= now)) i = 0;
     } while ((i < 0) && (errno == EINTR));
@@ -677,9 +656,8 @@ long tcp_soutr (TCPSTREAM *stream,char *
 
 long tcp_sout (TCPSTREAM *stream,char *string,unsigned long size)
 {
-  int i;
-  fd_set fds,efds;
-  struct timeval tmo;
+  int i, tmo;
+  struct pollfd pfd;
   time_t t = time (0);
   blocknotify_t bn = (blocknotify_t) mail_parameters (NIL,GET_BLOCKNOTIFY,NIL);
   if (stream->tcpso < 0) return NIL;
@@ -689,15 +667,12 @@ long tcp_sout (TCPSTREAM *stream,char *s
     time_t now = tl;
     time_t ti = ttmo_write ? now + ttmo_write : 0;
     if (tcpdebug) mm_log ("Writing to TCP",TCPDEBUG);
-    tmo.tv_usec = 0;
-    FD_ZERO (&fds);		/* initialize selection vector */
-    FD_ZERO (&efds);		/* handle errors too */
-    FD_SET (stream->tcpso,&fds);/* set bit in selection vector */
-    FD_SET(stream->tcpso,&efds);/* set bit in error selection vector */
+    pfd.fd = stream->tcpso;
+    pfd.events = POLLOUT;
     errno = NIL;		/* block and write */
     do {			/* block under timeout */
-      tmo.tv_sec = ti ? ti - now : 0;
-      i = select (stream->tcpso+1,NIL,&fds,&efds,ti ? &tmo : NIL);
+      tmo = ti ? ti - now : 0;
+      i = poll (&pfd, 1, ti ? tmo * 1000 : -1);
       now = time (0);		/* fake timeout if interrupt & time expired */
       if ((i < 0) && (errno == EINTR) && ti && (ti <= now)) i = 0;
     } while ((i < 0) && (errno == EINTR));
