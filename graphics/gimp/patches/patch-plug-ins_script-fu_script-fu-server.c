$NetBSD: patch-plug-ins_script-fu_script-fu-server.c,v 1.3 2013/02/16 19:43:03 adam Exp $

AI_ADDRCONFIG is not defined on some platforms.

--- plug-ins/script-fu/script-fu-server.c.orig	2012-02-04 18:42:45.000000000 +0000
+++ plug-ins/script-fu/script-fu-server.c
@@ -460,7 +460,11 @@ server_start (gint         port,
   const gchar     *progress;
 
   memset (&hints, 0, sizeof (hints));
+#ifdef AI_ADDRCONFIG
   hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
+#else
+  hints.ai_flags = AI_PASSIVE;
+#endif
   hints.ai_socktype = SOCK_STREAM;
 
   port_s = g_strdup_printf ("%d", port);
