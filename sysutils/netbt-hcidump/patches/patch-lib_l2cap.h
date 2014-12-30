$NetBSD: patch-lib_l2cap.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/l2cap.h.orig	2012-06-13 15:04:20.000000000 +0000
+++ lib/l2cap.h
@@ -31,6 +31,7 @@
 extern "C" {
 #endif
 
+#if 0
 #include <sys/socket.h>
 
 /* L2CAP defaults */
@@ -71,6 +72,7 @@ struct l2cap_conninfo {
 #define L2CAP_LM_TRUSTED	0x0008
 #define L2CAP_LM_RELIABLE	0x0010
 #define L2CAP_LM_SECURE		0x0020
+#endif
 
 /* L2CAP command codes */
 #define L2CAP_COMMAND_REJ	0x01
