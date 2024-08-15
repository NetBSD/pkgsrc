$NetBSD: patch-channels_ainput_server_ainput__main.c,v 1.1 2024/08/15 20:41:32 markd Exp $

gcc14 (incompatible pointer types)

--- channels/ainput/server/ainput_main.c.orig	2024-04-22 09:26:59.000000000 +0000
+++ channels/ainput/server/ainput_main.c
@@ -222,7 +222,7 @@ static HANDLE ainput_server_get_channel_
 
 	WINPR_ASSERT(ainput);
 
-	if (WTSVirtualChannelQuery(ainput->ainput_channel, WTSVirtualEventHandle, &buffer,
+	if (WTSVirtualChannelQuery(ainput->ainput_channel, WTSVirtualEventHandle, (PVOID*) &buffer,
 	                           &BytesReturned) == TRUE)
 	{
 		if (BytesReturned == sizeof(HANDLE))
@@ -416,7 +416,7 @@ ainput_server_context* ainput_server_con
 		goto fail;
 	return &ainput->context;
 fail:
-	ainput_server_context_free(ainput);
+	ainput_server_context_free((ainput_server_context*) ainput);
 	return NULL;
 }
 
@@ -539,7 +539,7 @@ UINT ainput_server_context_poll_int(ainp
 			BYTE* buffer = NULL;
 			DWORD BytesReturned = 0;
 
-			if (WTSVirtualChannelQuery(ainput->ainput_channel, WTSVirtualChannelReady, &buffer,
+			if (WTSVirtualChannelQuery(ainput->ainput_channel, WTSVirtualChannelReady, (PVOID*) &buffer,
 			                           &BytesReturned) != TRUE)
 			{
 				WLog_ERR(TAG, "WTSVirtualChannelReady failed,");
