$NetBSD: patch-AvailableColumnsPanel.c,v 1.1 2015/08/20 13:38:25 jperkin Exp $

Restrict to ASCII characters.

--- AvailableColumnsPanel.c.orig	2011-12-26 21:51:00.000000000 +0000
+++ AvailableColumnsPanel.c
@@ -55,7 +55,7 @@ static HandlerResult AvailableColumnsPan
       }
       default:
       {
-         if (isalpha(ch))
+         if (isascii(ch) && isalpha(ch))
             result = Panel_selectByTyping(super, ch);
          break;
       }
