$NetBSD: patch-libfreerdp_core_redirection.c,v 1.1 2024/08/15 20:41:32 markd Exp $

gcc14 (incompatible pointer types)

--- libfreerdp/core/redirection.c.orig	2024-04-22 09:26:59.000000000 +0000
+++ libfreerdp/core/redirection.c
@@ -86,7 +86,7 @@ static void redirection_free_data(BYTE**
 	*str = NULL;
 }
 
-static BOOL redirection_copy_data(char** dst, UINT32* plen, const char* str, UINT32 len)
+static BOOL redirection_copy_data(BYTE** dst, UINT32* plen, const char* str, UINT32 len)
 {
 	redirection_free_data(dst, plen);
 
@@ -109,7 +109,7 @@ static BOOL freerdp_settings_set_pointer
 	switch (id)
 	{
 		case FreeRDP_TargetNetAddress:
-			pdata = &settings->TargetNetAddress;
+			pdata = (BYTE**) &settings->TargetNetAddress;
 			plen = &settings->TargetNetAddressCount;
 			break;
 		case FreeRDP_LoadBalanceInfo:
