$NetBSD: patch-gnet_inetaddr.c,v 1.1 2014/09/10 12:22:44 joerg Exp $

--- gnet/inetaddr.c.orig	2014-09-09 18:35:40.000000000 +0000
+++ gnet/inetaddr.c
@@ -1344,7 +1344,7 @@ gnet_inetaddr_new_list_async_cb (GIOChan
 	      int bytes_parsed;
 
 	      bytes_parsed = buf - state->buffer;
-	      g_memmove (state->buffer, buf, bytes_parsed);
+	      memmove (state->buffer, buf, bytes_parsed);
 	      state->len -= bytes_parsed;
 	      
 	      return TRUE;
