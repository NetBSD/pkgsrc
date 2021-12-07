$NetBSD: patch-lib_rpcChannel_rpcChannel.c,v 1.2 2021/12/07 18:25:46 adam Exp $

--- lib/rpcChannel/rpcChannel.c.orig	2021-08-31 09:03:11.000000000 +0000
+++ lib/rpcChannel/rpcChannel.c
@@ -308,7 +308,11 @@ RpcChannelXdrWrapper(RpcInData *data,
          goto exit;
       }
 
+#if defined(__NetBSD__)
+      if (!xdrProc(&xdrs, copy.result)) {
+#else
       if (!xdrProc(&xdrs, copy.result, 0)) {
+#endif
          ret = RPCIN_SETRETVALS(data, "XDR serialization failed.", FALSE);
 
          /*
@@ -378,7 +382,11 @@ RpcChannel_BuildXdrCommand(const char *c
       goto exit;
    }
 
+#if defined(__NetBSD__)
+   if (!proc(&xdrs, xdrData)) {
+#else
    if (!proc(&xdrs, xdrData, 0)) {
+#endif
       goto exit;
    }
 
