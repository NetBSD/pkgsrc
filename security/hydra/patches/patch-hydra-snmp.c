$NetBSD: patch-hydra-snmp.c,v 1.1 2013/09/20 23:10:12 joerg Exp $

--- hydra-snmp.c.orig	2013-08-02 11:35:56.000000000 +0000
+++ hydra-snmp.c
@@ -335,8 +335,8 @@ int start_snmp(int s, char *ip, int port
   // xor initVect with salt  
     for (i = 0; i < 8; i++)  
       initVect[i] ^= privacy_params[i];  
-    des_key_sched((C_Block*)key, symcbc);
-    des_ncbc_encrypt(snmpv3_get2 + 2, buf, sizeof(snmpv3_get2) - 2, symcbc, (C_Block*)(initVect), DES_ENCRYPT);
+    DES_key_sched((C_Block*)key, &symcbc);
+    DES_ncbc_encrypt(snmpv3_get2 + 2, buf, sizeof(snmpv3_get2) - 2, &symcbc, (C_Block*)(initVect), DES_ENCRYPT);
 
 #endif
 
