$NetBSD: patch-amidi_amidi.c,v 1.2 2023/11/23 16:15:04 ryoon Exp $

--- amidi/amidi.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ amidi/amidi.c
@@ -446,7 +446,7 @@ static void print_byte(unsigned char byt
 	printf("%02X", byte);
 }
 
-static void sig_handler(int)
+static void sig_handler(int sig ATTRIBUTE_UNUSED)
 {
 	stop = 1;
 }
