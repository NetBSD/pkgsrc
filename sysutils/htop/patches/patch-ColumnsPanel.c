$NetBSD: patch-ColumnsPanel.c,v 1.1 2015/08/20 13:38:25 jperkin Exp $

Restrict to ASCII characters.

--- ColumnsPanel.c.orig	2011-12-26 21:53:10.000000000 +0000
+++ ColumnsPanel.c
@@ -70,7 +70,7 @@ static HandlerResult ColumnsPanel_eventH
       }
       default:
       {
-         if (isalpha(ch))
+         if (isascii(ch) && isalpha(ch))
             result = Panel_selectByTyping(super, ch);
          if (result == BREAK_LOOP)
             result = IGNORED;
