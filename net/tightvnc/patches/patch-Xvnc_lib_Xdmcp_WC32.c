$NetBSD: patch-Xvnc_lib_Xdmcp_WC32.c,v 1.1 2013/10/26 00:28:02 asau Exp $

--- Xvnc/lib/Xdmcp/WC32.c.orig	2000-06-11 12:00:51.000000000 +0000
+++ Xvnc/lib/Xdmcp/WC32.c
@@ -34,9 +34,7 @@ in this Software without prior written a
 #include <X11/Xdmcp.h>
 
 int
-XdmcpWriteCARD32 (buffer, value)
-    XdmcpBufferPtr  buffer;
-    CARD32	    value;
+XdmcpWriteCARD32 (XdmcpBufferPtr buffer, unsigned value)
 {
     if (!XdmcpWriteCARD8 (buffer, value >> 24))
 	return FALSE;
