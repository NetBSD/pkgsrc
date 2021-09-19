$NetBSD: patch-slirp_src_tcp__subr.c,v 1.1 2021/09/19 13:49:12 yhardy Exp $

Issues:

 QEMU crashes when receiving network connection on NetBSD
 https://gitlab.com/qemu-project/qemu/-/issues/605

 Use the exact sockaddr size in getnameinfo call
 https://gitlab.freedesktop.org/slirp/libslirp/-/issues/52
 Fixed in commit: 23db43ab

--- slirp/src/tcp_subr.c.orig	2021-09-18 20:05:43.313555017 +0000
+++ slirp/src/tcp_subr.c
@@ -464,7 +464,7 @@ void tcp_connect(struct socket *inso)
     Slirp *slirp = inso->slirp;
     struct socket *so;
     struct sockaddr_storage addr;
-    socklen_t addrlen = sizeof(struct sockaddr_storage);
+    socklen_t addrlen;
     struct tcpcb *tp;
     int s, opt, ret;
     /* AF_INET6 addresses are bigger than AF_INET, so this is big enough. */
@@ -473,7 +473,17 @@ void tcp_connect(struct socket *inso)
 
     DEBUG_CALL("tcp_connect");
     DEBUG_ARG("inso = %p", inso);
-    ret = getnameinfo((const struct sockaddr *) &inso->lhost.ss, sizeof(inso->lhost.ss), addrstr, sizeof(addrstr), portstr, sizeof(portstr), NI_NUMERICHOST|NI_NUMERICSERV);
+    switch (inso->lhost.ss.ss_family) {
+    case AF_INET:
+        addrlen = sizeof(struct sockaddr_in);
+        break;
+    case AF_INET6:
+        addrlen = sizeof(struct sockaddr_in6);
+        break;
+    default:
+        g_assert_not_reached();
+    }
+    ret = getnameinfo((const struct sockaddr *) &inso->lhost.ss, addrlen, addrstr, sizeof(addrstr), portstr, sizeof(portstr), NI_NUMERICHOST|NI_NUMERICSERV);
     g_assert(ret == 0);
     DEBUG_ARG("ip = [%s]:%s", addrstr, portstr);
     DEBUG_ARG("so_state = 0x%x", inso->so_state);
@@ -494,6 +504,7 @@ void tcp_connect(struct socket *inso)
              * us again until the guest address is available.
              */
             DEBUG_MISC(" guest address not available yet");
+            addrlen = sizeof(addr);
             s = accept(inso->s, (struct sockaddr *)&addr, &addrlen);
             if (s >= 0) {
                 close(s);
@@ -518,6 +529,7 @@ void tcp_connect(struct socket *inso)
 
     tcp_mss(sototcpcb(so), 0);
 
+    addrlen = sizeof(addr);
     s = accept(inso->s, (struct sockaddr *)&addr, &addrlen);
     if (s < 0) {
         tcp_close(sototcpcb(so)); /* This will sofree() as well */
