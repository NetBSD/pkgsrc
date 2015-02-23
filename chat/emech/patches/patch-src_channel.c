$NetBSD: patch-src_channel.c,v 1.1 2015/02/23 18:18:42 joerg Exp $

--- src/channel.c.orig	2015-02-23 10:56:23.000000000 +0000
+++ src/channel.c
@@ -58,7 +58,7 @@ void check_idlekick(void)
 	}
 }
 
-__attr (CORE_SEG, regparm(2))
+__attr (CORE_SEG, __regparm(2))
 Chan *find_channel(char *name, int anychannel)
 {
 	Chan	*chan;
