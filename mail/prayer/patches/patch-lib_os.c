$NetBSD: patch-lib_os.c,v 1.1 2011/06/30 01:17:38 schnoebe Exp $

--- lib/os.c.orig	2011-01-18 13:32:50.000000000 +0000
+++ lib/os.c
@@ -175,7 +175,11 @@ int *os_bind_inet_socket(unsigned long p
 
     snprintf(port_str, sizeof(port_str), "%lu", port);
     bzero((void *) &ai_hints, sizeof(ai_hints));
+#ifdef AI_ADDRCONFIG
     ai_hints.ai_flags = AI_PASSIVE|AI_ADDRCONFIG;
+#else
+    ai_hints.ai_flags = AI_PASSIVE;
+#endif
     ai_hints.ai_family = AF_UNSPEC;
     ai_hints.ai_socktype = SOCK_STREAM;
 
