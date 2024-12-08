$NetBSD: patch-io_io__waituntil2.c,v 1.1 2024/12/08 23:08:15 hgutch Exp $

- EVFILT_READ/EVFILT_WRITE are magic numbers, not bit flags.  Without
  this, the EVFILT_READ test always fails on NetBSD (and always
  succeeds on FreeBSD/OpenBSD) and as a result, calling io_wait()
  always immediately returns (instead of blocking) even if there is no
  data to be read.  In practice this means that programs using this
  will most likely spin at 100% CPU.
- Fix test for EVFILT_READ instead of EVFILT_WRITE.
- Fix the test for the whole "e->canread" optimization;  this did not
  lead to wrong behavior, but this invalidates the whole optimization
  of libowfat not asking the kernel for additional data to read until
  the consumer has finally read from this descriptor.

--- io/io_waituntil2.c.orig	2022-03-11 12:07:54.000000000 +0000
+++ io/io_waituntil2.c
@@ -184,7 +184,7 @@ int64 io_waituntil2(int64 milliseconds) 
 
 	/* if we think we can not read, but the kernel tells us that we
 	 * can, put this fd in the relevant data structures */
-	if (!e->canread && (y[i].events&(EPOLLIN|EPOLLPRI|EPOLLRDNORM|EPOLLRDBAND))) {
+	if (y[i].events&(EPOLLIN|EPOLLPRI|EPOLLRDNORM|EPOLLRDBAND)) {
 	  if (e->canread) {
 	    newevents &= ~EPOLLIN;
 	  } else {
@@ -294,7 +294,7 @@ int64 io_waituntil2(int64 milliseconds) 
 
 	/* if we think we can not read, but the kernel tells us that we
 	 * can, put this fd in the relevant data structures */
-	if (!e->canread && (y[n].filter&EVFILT_WRITE)) {
+	if (y[n].filter == EVFILT_READ) {
 	  if (e->canread) {
 	    newevents &= ~POLLIN;
 	    EV_SET(kev+nkev, y[n].ident, EVFILT_READ, EV_DELETE, 0, 0, 0); ++nkev;
@@ -308,7 +308,7 @@ int64 io_waituntil2(int64 milliseconds) 
 	}
 
 	/* if the kernel says the fd is writable, ... */
-	if (y[i].filter&EVFILT_WRITE) {
+	if (y[i].filter == EVFILT_WRITE) {
 	  /* Usually, if the kernel says a descriptor is writable, we
 	   * note it and do not tell the kernel not to tell us again.
 	   * The idea is that once we notify the caller that the fd is
