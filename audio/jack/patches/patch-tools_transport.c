$NetBSD: patch-tools_transport.c,v 1.1 2019/06/15 08:21:33 adam Exp $

--- tools/transport.c.orig	2008-11-11 17:36:30.000000000 -0500
+++ tools/transport.c
@@ -29,6 +29,10 @@
 #include <jack/jack.h>
 #include <jack/transport.h>
 
+#ifndef whitespace
+#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
+#endif
+
 char *package;				/* program name */
 int done = 0;
 jack_client_t *client;
