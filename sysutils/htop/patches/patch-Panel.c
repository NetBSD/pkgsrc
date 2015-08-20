$NetBSD: patch-Panel.c,v 1.1 2015/08/20 13:38:25 jperkin Exp $

Restrict to ASCII characters.

--- Panel.c.orig	2012-02-02 23:45:01.000000000 +0000
+++ Panel.c
@@ -417,7 +417,7 @@ HandlerResult Panel_selectByTyping(Panel
    if (!this->eventHandlerBuffer)
       this->eventHandlerBuffer = calloc(100, 1);
 
-   if (isalnum(ch)) {
+   if (isascii(ch) && isalnum(ch)) {
       int len = strlen(this->eventHandlerBuffer);
       if (len < 99) {
          this->eventHandlerBuffer[len] = ch;
