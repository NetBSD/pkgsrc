$NetBSD: patch-curvecp_curvecpserver.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Part of Debian 0004-fix-segfault.patch:
Fix segfault.

Also part of Debian 0009-return-correct-client-extension.patch:
Return correct client extension.

--- curvecp/curvecpserver.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/curvecpserver.c
@@ -90,6 +90,7 @@ int ipparse(unsigned char *y,const char 
   long long k;
   long long d;
 
+  if (!x) return 0;
   for (k = 0;k < 4;++k) y[k] = 0;
   for (k = 0;k < 4;++k) {
     d = 0;
@@ -473,7 +474,7 @@ int main(int argc,char **argv)
 	    byte_copy(text + 32,r,activeclients[i].message + 1);
 	    crypto_box_afternm(text,text,r + 32,nonce,activeclients[i].clientshortservershort);
 	    byte_copy(packet,8,"RL3aNMXM");
-	    byte_copy(packet + 8,16,clientextension);
+	    byte_copy(packet + 8,16,activeclients[i].clientextension);
 	    byte_copy(packet + 24,16,serverextension);
 	    byte_copy(packet + 40,8,nonce + 16);
 	    byte_copy(packet + 48,r + 16,text + 16);
