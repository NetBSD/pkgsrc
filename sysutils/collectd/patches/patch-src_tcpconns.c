$NetBSD: patch-src_tcpconns.c,v 1.2 2014/06/14 12:21:02 fhajny Exp $

--- src/tcpconns.c.orig	2014-01-26 08:09:14.000000000 +0000
+++ src/tcpconns.c
@@ -893,6 +893,7 @@ static int conn_init (void)
   return (0);
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read (void)
 {
   struct inpcbtable table;
@@ -912,7 +913,11 @@ static int conn_read (void)
   /* Get the `head' pcb */
   head = (struct inpcb *) &(inpcbtable_ptr->inpt_queue);
   /* Get the first pcb */
+#if __NetBSD_Version__ >= 699000000
+  next = (struct inpcb *)TAILQ_FIRST (&table.inpt_queue);
+#else
   next = (struct inpcb *)CIRCLEQ_FIRST (&table.inpt_queue);
+#endif
 
   while (next != head)
   {
@@ -920,7 +925,11 @@ static int conn_read (void)
     kread ((u_long) next, &inpcb, sizeof (inpcb));
 
     /* Advance `next' */
+#if __NetBSD_Version__ >= 699000000
+    next = (struct inpcb *)TAILQ_NEXT (&inpcb, inp_queue);
+#else
     next = (struct inpcb *)CIRCLEQ_NEXT (&inpcb, inp_queue);
+#endif
 
     /* Ignore sockets, that are not connected. */
 #ifdef __NetBSD__
