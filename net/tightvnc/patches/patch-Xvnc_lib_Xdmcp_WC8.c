$NetBSD: patch-Xvnc_lib_Xdmcp_WC8.c,v 1.1 2013/07/02 12:15:36 joerg Exp $

--- Xvnc/lib/Xdmcp/WC8.c.orig	2013-06-25 21:43:55.000000000 +0000
+++ Xvnc/lib/Xdmcp/WC8.c
@@ -34,9 +34,7 @@ in this Software without prior written a
 #include <X11/Xdmcp.h>
 
 int
-XdmcpWriteCARD8 (buffer, value)
-    XdmcpBufferPtr  buffer;
-    CARD8	    value;
+XdmcpWriteCARD8(XdmcpBufferPtr buffer, unsigned value)
 {
     if (buffer->pointer >= buffer->size)
 	return FALSE;
