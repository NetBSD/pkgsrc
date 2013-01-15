$NetBSD: patch-message.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- message.c.orig	2013-01-14 16:37:42.000000000 +0000
+++ message.c
@@ -51,8 +51,7 @@ int		color, time;
 	Called dumb because the procedure is ugly and the messages are mostly
 	snide remarks.
 */
-dumb_message(kind)
-int	kind;
+void dumb_message(int kind)
 {
 	register int	opinion, num;
 
