$NetBSD: patch-lib_rpcChannel_rpcChannel.c,v 1.1 2016/12/23 04:11:03 ryoon Exp $

--- lib/rpcChannel/rpcChannel.c.orig	2016-09-29 10:07:22.000000000 +0000
+++ lib/rpcChannel/rpcChannel.c
@@ -272,7 +272,11 @@ RpcChannelXdrWrapper(RpcInData *data,
          goto exit;
       }
 
+#if defined(__NetBSD__)
+      if (!xdrProc(&xdrs, copy.result)) {
+#else
       if (!xdrProc(&xdrs, copy.result, 0)) {
+#endif
          ret = RPCIN_SETRETVALS(data, "XDR serialization failed.", FALSE);
          DynXdr_Destroy(&xdrs, TRUE);
          goto exit;
@@ -330,7 +334,11 @@ RpcChannel_BuildXdrCommand(const char *c
       goto exit;
    }
 
+#if defined(__NetBSD__)
+   if (!proc(&xdrs, xdrData)) {
+#else
    if (!proc(&xdrs, xdrData, 0)) {
+#endif
       goto exit;
    }
 
