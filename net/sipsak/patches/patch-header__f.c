$NetBSD: patch-header__f.c,v 1.1 2013/01/11 00:01:33 joerg Exp $

--- header_f.c.orig	2013-01-10 23:04:22.000000000 +0000
+++ header_f.c
@@ -604,7 +604,7 @@ void print_message_line(char *message)
 }
 
 /* return pointer to the beginning of the message body */
-inline char* get_body(char *mes) {
+char* get_body(char *mes) {
 	char *cr;
 
 	if ((cr = strstr(mes, "\r\n\r\n")) != NULL) {
