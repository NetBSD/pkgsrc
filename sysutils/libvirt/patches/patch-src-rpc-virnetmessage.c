$NetBSD: patch-src-rpc-virnetmessage.c,v 1.1 2014/01/25 02:54:27 agc Exp $

fix for # of args in xdrproc_t on NetBSD

--- src/rpc/virnetmessage.c	2014/01/25 02:27:37	1.1
+++ src/rpc/virnetmessage.c	2014/01/25 02:30:04
@@ -345,7 +345,11 @@
                   msg->bufferLength - msg->bufferOffset, XDR_ENCODE);
 
     /* Try to encode the payload. If the buffer is too small increase it. */
+#ifdef __NetBSD__
+    while (!(*filter)(&xdr, data)) {
+#else
     while (!(*filter)(&xdr, data, 0)) {
+#endif
         unsigned int newlen = (msg->bufferLength - VIR_NET_MESSAGE_LEN_MAX) * 4;
 
         if (newlen > VIR_NET_MESSAGE_MAX) {
@@ -402,7 +406,11 @@
     xdrmem_create(&xdr, msg->buffer + msg->bufferOffset,
                   msg->bufferLength - msg->bufferOffset, XDR_DECODE);
 
+#ifdef __NetBSD__
+    if (!(*filter)(&xdr, data)) {
+#else
     if (!(*filter)(&xdr, data, 0)) {
+#endif
         virReportError(VIR_ERR_RPC, "%s", _("Unable to decode message payload"));
         goto error;
     }
