$NetBSD: patch-src_Mixfix_modules.yy,v 1.1 2013/11/29 18:30:10 joerg Exp $

--- src/Mixfix/modules.yy.orig	2013-11-28 01:36:15.000000000 +0000
+++ src/Mixfix/modules.yy
@@ -247,7 +247,7 @@ viewEndOpMap	:	':'
 			  //	press on.
 			  //
 			  opDescription = lexerBubble;
-			  lexBubble(END_STATEMENT, 1)
+			  lexBubble(END_STATEMENT, 1);
 			}
 			endBubble
 			{
