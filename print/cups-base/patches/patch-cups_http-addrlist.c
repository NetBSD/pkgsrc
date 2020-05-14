$NetBSD: patch-cups_http-addrlist.c,v 1.1 2020/05/14 19:45:50 joerg Exp $

Checkout for non-blocking connect is difficult as systems can't agree on
whether it is a write condition or an error. Check for both with
poll/select and if either flag is set, use getpeername to determine if
the socket was really connected. If it wasn't, drop it correctly from the
poll event list as well as to not check stale event masks.

--- cups/http-addrlist.c.orig	2020-05-09 14:07:20.638266583 +0000
+++ cups/http-addrlist.c
@@ -73,8 +73,7 @@ httpAddrConnect2(
 #  ifdef HAVE_POLL
   struct pollfd		pfds[100];	/* Polled file descriptors */
 #  else
-  fd_set		input_set,	/* select() input set */
-			output_set,	/* select() output set */
+  fd_set		output_set,	/* select() output set */
 			error_set;	/* select() error set */
   struct timeval	timeout;	/* Timeout */
 #  endif /* HAVE_POLL */
@@ -280,16 +279,15 @@ httpAddrConnect2(
       DEBUG_printf(("1httpAddrConnect2: poll() returned %d (%d)", result, errno));
 
 #  else
-      FD_ZERO(&input_set);
+      FD_ZERO(&output_set);
       for (i = 0; i < nfds; i ++)
-	FD_SET(fds[i], &input_set);
-      output_set = input_set;
-      error_set  = input_set;
+	FD_SET(fds[i], &output_set);
+      error_set  = output_set;
 
       timeout.tv_sec  = 0;
       timeout.tv_usec = (addrlist ? 100 : remaining > 250 ? 250 : remaining) * 1000;
 
-      result = select(max_fd + 1, &input_set, &output_set, &error_set, &timeout);
+      result = select(max_fd + 1, NULL, &output_set, &error_set, &timeout);
 
       DEBUG_printf(("1httpAddrConnect2: select() returned %d (%d)", result, errno));
 #  endif /* HAVE_POLL */
@@ -308,38 +306,25 @@ httpAddrConnect2(
       {
 #  ifdef HAVE_POLL
 	DEBUG_printf(("pfds[%d].revents=%x\n", i, pfds[i].revents));
-	if (pfds[i].revents && !(pfds[i].revents & (POLLERR | POLLHUP)))
+	if (pfds[i].revents)
 #  else
-	if (FD_ISSET(fds[i], &input_set) && !FD_ISSET(fds[i], &error_set))
+	if (FD_ISSET(fds[i], &output_set) || FD_ISSET(fds[i], &error_set))
 #  endif /* HAVE_POLL */
 	{
-	  *sock    = fds[i];
-	  connaddr = addrs[i];
-
-#  ifdef DEBUG
-	  len   = sizeof(peer);
-	  if (!getpeername(fds[i], (struct sockaddr *)&peer, &len))
-	    DEBUG_printf(("1httpAddrConnect2: Connected to %s:%d...", httpAddrString(&peer, temp, sizeof(temp)), httpAddrPort(&peer)));
-#  endif /* DEBUG */
-
-          break;
-	}
-#  ifdef HAVE_POLL
-	else if (pfds[i].revents & (POLLERR | POLLHUP))
-#  else
-	else if (FD_ISSET(fds[i], &error_set))
-#  endif /* HAVE_POLL */
-        {
-         /*
-          * Error on socket, remove from the "pool"...
-          */
-
+	  if (getpeername(fds[i], NULL, 0) == 0) {
+	    *sock    = fds[i];
+	    connaddr = addrs[i];
+	    break;
+	  }
 	  httpAddrClose(NULL, fds[i]);
           nfds --;
           if (i < nfds)
           {
             memmove(fds + i, fds + i + 1, (size_t)(nfds - i) * (sizeof(fds[0])));
             memmove(addrs + i, addrs + i + 1, (size_t)(nfds - i) * (sizeof(addrs[0])));
+#  ifdef HAVE_POLL
+            memmove(pfds + i, pfds + i + 1, (size_t)(nfds - i) * (sizeof(pfds[0])));
+#  endif /* HAVE_POLL */
           }
           i --;
         }
