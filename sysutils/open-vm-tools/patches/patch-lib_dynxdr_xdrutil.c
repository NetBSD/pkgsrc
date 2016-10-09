$NetBSD: patch-lib_dynxdr_xdrutil.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/dynxdr/xdrutil.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/dynxdr/xdrutil.c
@@ -102,7 +102,11 @@ XdrUtil_Deserialize(const void *data,  /
    ASSERT(dest != NULL);
 
    xdrmem_create(&xdrs, (char *) data, dataLen, XDR_DECODE);
+#if defined(__NetBSD__)
+   ret = (Bool) proc(&xdrs, dest);
+#else
    ret = (Bool) proc(&xdrs, dest, 0);
+#endif
    xdr_destroy(&xdrs);
 
    if (!ret) {
