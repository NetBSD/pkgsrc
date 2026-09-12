$NetBSD: patch-trickle-overload.c,v 1.1 2026/09/12 15:04:23 wiz Exp $

On NetBSD the socket() and select() interceptors resolved the wrong
libc symbol: the wrappers are exported as __socket30 / __select50
(the headers rename them), but GETADDR looked up the plain names.
Resolve __socket30 / __select50 on NetBSD, mask SOCK_NONBLOCK and
SOCK_CLOEXEC out of the socket type before the AF_INET/SOCK_STREAM
test, add NetBSD to the poll() platform conditionals, and pass the
timeval by pointer in select_shift().  Part of a patch posted to
netbsd-users on 2025-02-20 that fixes the Memory fault crash on NetBSD.

--- trickle-overload.c.orig
+++ trickle-overload.c
@@ -196,7 +196,12 @@
 
 	GETADDR(write);
 
+#ifdef __NetBSD__
+	if ((libc_socket = dlsym(dh, "__socket30")) == NULL)
+		errx(0, "[trickle] Failed to get __socket30() address");
+#else
 	GETADDR(socket);
+#endif
 /*	GETADDR(setsockopt); */
 	GETADDR(close);
 
@@ -213,7 +218,12 @@
 #endif /* !__FreeBSD__ */
 	GETADDR(sendto);
 
+#ifdef __NetBSD__
+	if ((libc_select = dlsym(dh, "__select50")) == NULL)
+		errx(0, "[trickle] Failed to get __select50() address");
+#else
 	GETADDR(select);
+#endif
 //	GETADDR(poll);
 
 	GETADDR(dup);
@@ -302,6 +312,13 @@
 	    domain, type, protocol, sock);
 #endif /* DEBUG */
 
+#ifdef SOCK_NONBLOCK
+	type &= ~SOCK_NONBLOCK;
+#endif
+#ifdef SOCK_CLOEXEC
+	type &= ~SOCK_CLOEXEC;
+#endif
+
 	if (sock != -1 && domain == AF_INET && type == SOCK_STREAM) {
 		if ((sd = calloc(1, sizeof(*sd))) == NULL)
 			return (-1);
@@ -311,7 +328,6 @@
 		}
 
 		/* All sockets are equals. */
-		sd->stat->pts = 1;
 		sd->stat->lsmooth = lsmooth;
 		sd->stat->tsmooth = tsmooth;
 		sd->sock = sock;
@@ -393,18 +409,14 @@
 }
 
 static struct delay *
-select_shift(struct delayhead *dhead, struct timeval *inittv,
+select_shift(struct delayhead *dhead, struct timeval *difftv,
     struct timeval **delaytv)
 {
-	struct timeval curtv, difftv;
 	struct delay *d;
 	struct sockdesc *sd;
 
-	gettimeofday(&curtv, NULL);
-	timersub(&curtv, inittv, &difftv);
-
 	TAILQ_FOREACH(d, dhead, next) {
-		if (timercmp(&d->delaytv, &difftv, >))
+		if (timercmp(&d->delaytv, difftv, >))
 			break;
 		sd = d->sd;
 
@@ -413,7 +425,7 @@
 	}
 
 	if (d != NULL)
-		timersub(&d->delaytv, &difftv, *delaytv);
+		timersub(&d->delaytv, difftv, *delaytv);
 	else 
 		*delaytv = NULL;
 
@@ -431,8 +443,8 @@
 {
 	struct sockdesc *sd;
 	fd_set *fdsets[] = { wfds, rfds }, *fds;
-	struct timeval *delaytv, *selecttv = NULL, *timeout = NULL, _timeout,
-	    inittv, curtv, difftv;
+	struct timeval *delaytv, _delaytv, *selecttv = NULL, *timeout = NULL,
+	    _timeout, inittv, curtv, difftv;
 	short which;
 	struct delayhead dhead;
 	struct delay *d, *_d;
@@ -462,15 +474,18 @@
 			    FD_ISSET(sd->sock, fds) &&
 			    select_delay(&dhead, sd, which)) {
 				FD_CLR(sd->sock, fds);
-				nfds--;
 			}
 
 	gettimeofday(&inittv, NULL);
 	curtv = inittv;
 	d = TAILQ_FIRST(&dhead);
-	delaytv = d != NULL ? &d->delaytv : NULL;
+	if (d != NULL) {
+		_delaytv = d->delaytv;
+		delaytv = &_delaytv;
+	} else
+		delaytv = NULL;
+	timersub(&curtv, &inittv, &difftv);
  again:
-	timersub(&inittv, &curtv, &difftv);
 	selecttv = NULL;
 
 	if (delaytv != NULL)
@@ -498,15 +513,15 @@
 #endif /* DEBUG */
 
 	if (ret == 0 && delaytv != NULL && selecttv == delaytv) {
-		_d = select_shift(&dhead, &inittv, &delaytv);
+		gettimeofday(&curtv, NULL);
+		timersub(&curtv, &inittv, &difftv);
+		_d = select_shift(&dhead, &difftv, &delaytv);
 		while ((d = TAILQ_FIRST(&dhead)) != _d) {
 			FD_SET(d->sd->sock, fdsets[d->which]);
-			nfds++;
 			TAILQ_REMOVE(&dhead, d, next);
 			free(d);
 		}
 
-		gettimeofday(&curtv, NULL);
 		goto again;
 	}
 
@@ -522,10 +537,10 @@
 #define POLL_WRMASK (POLLOUT | POLLWRNORM | POLLWRBAND)
 #define POLL_RDMASK (POLLIN | /* POLLNORM | */  POLLPRI | POLLRDNORM | POLLRDBAND)
 
-#if defined(__linux__) || (defined(__svr4__) && defined(__sun__)) || defined(__OpenBSD__)
+#if defined(__linux__) || (defined(__svr4__) && defined(__sun__)) || defined(__OpenBSD__) || defined(__NetBSD__)
 int
 poll(struct pollfd *fds, nfds_t nfds, int __timeout)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 int
 poll(struct pollfd *fds, unsigned int nfds, int __timeout)
 #else
@@ -994,7 +1009,6 @@
 		}
 
 		sd->sock = ret;
-		sd->stat->pts = 1;
 		sd->stat->lsmooth = lsmooth;
 		sd->stat->tsmooth = tsmooth;
 		TAILQ_INSERT_TAIL(&sdhead, sd, next);
