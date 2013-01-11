$NetBSD: patch-packet.c,v 1.1 2013/01/11 00:03:30 joerg Exp $

--- packet.c.orig	2013-01-10 22:38:16.000000000 +0000
+++ packet.c
@@ -520,9 +520,7 @@ u_char *pak;
     return (0);
 }
 
-send_error_reply(type, msg)
-int type;
-char *msg;
+void send_error_reply(int type, char *msg)
 {
     switch (type) {
     case TAC_PLUS_AUTHEN:
