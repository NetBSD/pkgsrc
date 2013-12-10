$NetBSD: patch-src_mping.c,v 1.1 2013/12/10 13:59:16 jperkin Exp $

Provide compat MIN()

--- src/mping.c.orig	2004-12-17 01:45:56.000000000 +0000
+++ src/mping.c
@@ -121,6 +121,10 @@ OTHER:
 #define MAXWAIT         10              /* max time to wait for response, sec. */
 #define MAXPACKET       (65536-60-8)    /* max packet size */
 
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
 /* Various options */
 int options;
 #define F_INTERVAL        0x001
