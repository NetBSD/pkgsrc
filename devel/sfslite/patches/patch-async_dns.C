$NetBSD: patch-async_dns.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Clean up %m abuse.

--- async/dns.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/dns.C
@@ -156,13 +156,13 @@ resolver::udpinit ()
   udpsock = NULL;
   int fd = socket (addr->sa_family, SOCK_DGRAM, 0);
   if (fd < 0) {
-    warn ("resolver::udpsock: socket: %m\n");
+    warn ("resolver::udpsock: socket: %s\n", strerror(errno));
     return false;
   }
   make_async (fd);
   close_on_exec (fd);
   if (connect (fd, addr, addrlen) < 0) {
-    warn ("resolver::udpsock: connect: %m\n");
+    warn ("resolver::udpsock: connect: %s\n", strerror(errno));
     close (fd);
     return false;
   }
@@ -177,7 +177,7 @@ resolver::tcpinit ()
   tcpsock = NULL;
   int fd = socket (addr->sa_family, SOCK_STREAM, 0);
   if (fd < 0) {
-    warn ("resolver::tcpsock: socket: %m\n");
+    warn ("resolver::tcpsock: socket: %s\n", strerror(errno));
     return false;
   }
   make_async (fd);
@@ -415,7 +415,7 @@ resolv_conf::reload_cb (ref<bool> d, boo
   reload_lock = false;
   last_reload = sfs_get_timenow();
   if (!newres) {
-    warn ("resolv_conf::reload_cb: fork: %m\n");
+    warn ("resolv_conf::reload_cb: fork: %s\n", strerror(errno));
     setsock (true);
     return;
   }
