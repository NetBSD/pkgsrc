$NetBSD: patch-src_emu_input.c,v 1.1 2011/04/04 12:09:03 wiz Exp $

toupper is a macro on NetBSD.
Sent upstream.

--- src/emu/input.c.orig	2011-03-29 08:50:06.000000000 +0000
+++ src/emu/input.c
@@ -829,7 +829,7 @@ void input_device_item_add(input_device 
 	if (itemid > ITEM_ID_MAXIMUM)
 	{
 		/* copy the item name, removing spaces/underscores and making all caps */
-		item->token.cpy(name).toupper().delchr(' ').delchr('_');
+		item->token.cpy(name).upper().delchr(' ').delchr('_');
 	}
 
 	/* otherwise, make sure we have a valid standard token */
