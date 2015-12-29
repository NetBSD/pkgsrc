$NetBSD: patch-src_Mixfix_commands.yy,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix syntax.

--- src/Mixfix/commands.yy.orig	2013-11-28 01:20:49.000000000 +0000
+++ src/Mixfix/commands.yy
@@ -23,12 +23,12 @@
 /*
  *	Commands.
  */
-command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1) }
+command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1); }
 			endBubble
 			{
 			  interpreter.setCurrentModule(lexerBubble);
 			}
-		|	KW_DUMP			{ lexBubble(END_COMMAND, 1) }
+		|	KW_DUMP			{ lexBubble(END_COMMAND, 1); }
 			endBubble
 			{
 			  if (interpreter.setCurrentModule(lexerBubble))
