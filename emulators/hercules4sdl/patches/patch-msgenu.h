$NetBSD: patch-msgenu.h,v 1.1 2021/11/06 16:43:23 rhialto Exp $

Introduce 2 message texts as added to tuntap.c.

--- msgenu.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ msgenu.h
@@ -322,8 +322,8 @@ LOGM_DLL_IMPORT int  panel_command_captu
 #define HHC00153 "Net device %s: Invalid prefix length %s"
 #define HHC00154 "Preconfigured interface %s does not exist or is not accessible by Hercules (EPERM)"
 #define HHC00155 "Net device %s: Invalid broadcast address %s"
-//efine HHC00156 (available)
-//efine HHC00157 (available)
+#define HHC00156 "IFF_TUN requested but not a tun device: %s"
+#define HHC00157 "IFF_TAP requested but not a tap device: %s"
 //efine HHC00158 (available)
 //efine HHC00159 (available)
 #define HHC00160 "SCP %scommand: %s"
