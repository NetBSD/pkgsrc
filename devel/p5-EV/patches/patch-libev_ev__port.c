$NetBSD: patch-libev_ev__port.c,v 1.1 2019/11/11 04:16:34 gutteridge Exp $

Fix assert() syntax.

--- libev/ev_port.c.orig	2019-06-25 23:42:03.000000000 +0000
+++ libev/ev_port.c
@@ -70,7 +70,7 @@ port_associate_and_check (EV_P_ int fd,
     {
       if (errno == EBADFD)
         {
-          assert (("libev: port_associate found invalid fd", errno != EBADFD);
+          assert (("libev: port_associate found invalid fd", errno != EBADFD));
           fd_kill (EV_A_ fd);
         }
       else
