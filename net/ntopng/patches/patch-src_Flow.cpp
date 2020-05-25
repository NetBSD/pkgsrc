$NetBSD: patch-src_Flow.cpp,v 1.1 2020/05/25 20:26:51 adam Exp $

Match NDPI 3.2 interface.

--- src/Flow.cpp.orig	2020-05-25 09:50:19.000000000 +0000
+++ src/Flow.cpp
@@ -3512,7 +3512,7 @@ void Flow::dissectNetBIOS(u_int8_t *payl
 
   if(((payload[2] & 0x80) /* NetBIOS Response */ || ((payload[2] & 0x78) == 0x28 /* NetBIOS Registration */))
      && (payload_len >= 12)
-     && (ndpi_netbios_name_interpret((char*)&payload[12], payload_len - 12, name, sizeof(name)) > 0)
+     && (ndpi_netbios_name_interpret((char*)&payload[12], name, sizeof(name)) > 0)
      && (!strstr(name, "__MSBROWSE__"))
      ) {
 
