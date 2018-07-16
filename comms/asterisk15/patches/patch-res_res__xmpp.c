$NetBSD: patch-res_res__xmpp.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_xmpp.c.orig	2018-06-19 21:29:29.310245367 +0000
+++ res/res_xmpp.c
@@ -3746,7 +3746,7 @@ static int xmpp_client_receive(struct as
 			/* if we stumble on the ending tag character,
 			   we skip any whitespace that follows it*/
 			if (c == '>') {
-				while (isspace(buf[pos+1])) {
+				while (isspace((unsigned char)buf[pos+1])) {
 					pos++;
 				}
 			}
