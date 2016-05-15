$NetBSD: patch-hw_misc_ivshmem.c,v 1.1 2016/05/15 01:25:15 ryoon Exp $

--- hw/misc/ivshmem.c.orig	2016-05-11 15:56:09.000000000 +0000
+++ hw/misc/ivshmem.c
@@ -567,7 +567,9 @@ static void process_msg_connect(IVShmemS
     vector = peer->nb_eventfds++;
 
     IVSHMEM_DPRINTF("eventfds[%d][%d] = %d\n", posn, vector, fd);
+#if defined(CONFIG_EVENTFD)
     event_notifier_init_fd(&peer->eventfds[vector], fd);
+#endif
     fcntl_setfl(fd, O_NONBLOCK); /* msix/irqfd poll non block */
 
     if (posn == s->vm_id) {
