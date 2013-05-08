$NetBSD: patch-utf8.c,v 1.1 2013/05/08 18:03:44 minskim Exp $

Remove some Korean characters from the zero-width list.
(http://sourceforge.net/p/tmux/tickets/41/)

--- utf8.c.orig	2013-02-10 16:20:15.000000000 +0000
+++ utf8.c
@@ -173,7 +173,7 @@ struct utf8_width_entry utf8_width_table
 	{ 0x30000, 0x3fffd, 2, NULL, NULL },
 	{ 0x00711, 0x00711, 0, NULL, NULL },
 	{ 0x0fe00, 0x0fe0f, 0, NULL, NULL },
-	{ 0x01160, 0x011ff, 0, NULL, NULL },
+	{ 0x01160, 0x011ff, 1, NULL, NULL },
 	{ 0x0180b, 0x0180d, 0, NULL, NULL },
 	{ 0x10a3f, 0x10a3f, 0, NULL, NULL },
 	{ 0x00981, 0x00981, 0, NULL, NULL },
