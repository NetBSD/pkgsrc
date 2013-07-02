$NetBSD: patch-Xvnc_lib_Xdmcp_WC16.c,v 1.1 2013/07/02 12:15:36 joerg Exp $

--- Xvnc/lib/Xdmcp/WC16.c.orig	2013-06-25 21:44:37.000000000 +0000
+++ Xvnc/lib/Xdmcp/WC16.c
@@ -34,9 +34,7 @@ in this Software without prior written a
 #include <X11/Xdmcp.h>
 
 int
-XdmcpWriteCARD16 (buffer, value)
-    XdmcpBufferPtr  buffer;
-    CARD16	    value;
+XdmcpWriteCARD16 (XdmcpBufferPtr buffer, unsigned value)
 {
     if (!XdmcpWriteCARD8 (buffer, value >> 8))
 	return FALSE;
