$NetBSD: patch-client_X11_xf__graphics.c,v 1.1 2024/08/15 20:41:32 markd Exp $

gcc14 (int conversion)

--- client/X11/xf_graphics.c.orig	2024-04-22 09:26:59.000000000 +0000
+++ client/X11/xf_graphics.c
@@ -438,7 +438,7 @@ static BOOL xf_Pointer_New(rdpContext* c
 
 #endif
 fail:
-	WLog_DBG(TAG, "%s: %ld", __func__, rc ? pointer : -1);
+	WLog_DBG(TAG, "%s: %ld", __func__, rc ? (long) pointer : -1);
 	return rc;
 }
 
