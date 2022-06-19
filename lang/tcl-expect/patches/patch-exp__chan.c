$NetBSD: patch-exp__chan.c,v 1.2 2022/06/19 14:43:28 gdt Exp $

Add hack to work around deadlock situation that occurs on Solaris and
Linux. See PR 34442.

The problem apparently does not occur on BSD, but it doesn't seem to
be clear why or whether that's really the case; the description of the
problem as far as it's understood seems to be portable. So don't
conditionalize it, as the check should be safe. If this turns out to
cause problems, we can wrap it in ifdefs.

\todo File changes upstream (but upstream is not functioning).

--- exp_chan.c.orig	2010-07-01 00:53:49.000000000 +0000
+++ exp_chan.c
@@ -7,6 +7,7 @@
  */
 
 #include <sys/types.h>
+#include <sys/poll.h>
 #include <stdio.h>
 #include <signal.h>
 #include <errno.h>
@@ -205,6 +206,8 @@ ExpInputProc(instanceData, buf, toRead, 
     ExpState *esPtr = (ExpState *) instanceData;
     int bytesRead;			/* How many bytes were actually
                                          * read from the input device? */
+    struct pollfd fds[1];
+    int pollResult;
 
     *errorCodePtr = 0;
     
@@ -215,6 +218,18 @@ ExpInputProc(instanceData, buf, toRead, 
      * nonblocking, the read will never block.
      */
 
+    /* Update: there isn't always, which can lead to hangs. See PR 34442. */
+    fds[0].fd = esPtr->fdin;
+    fds[0].events = POLLIN | POLLERR | POLLHUP | POLLNVAL;
+    pollResult = poll(fds, 1, 0);
+    if (pollResult <= 0) {
+        *errorCodePtr = EWOULDBLOCK;
+	return -1;
+    } else if (fds[0].revents & (POLLERR | POLLHUP | POLLNVAL)) {
+        *errorCodePtr = EBADF;
+	return -1;
+    }
+
     bytesRead = read(esPtr->fdin, buf, (size_t) toRead);
     /*printf("ExpInputProc: read(%d,,) = %d\r\n",esPtr->fdin,bytesRead);*/
     if (bytesRead > -1) {
