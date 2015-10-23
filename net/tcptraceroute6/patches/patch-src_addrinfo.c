$NetBSD: patch-src_addrinfo.c,v 1.1 2015/10/23 09:52:35 he Exp $

Avoid use of AI_ADDRCONFIG if it's missing.

--- src/addrinfo.c.orig	2010-05-01 07:49:06.000000000 +0000
+++ src/addrinfo.c
@@ -196,7 +196,9 @@ int main (int argc, char *argv[])
 				break;
 
 			case 'c':
+#ifdef AI_ADDRCONFIG
 				aflags |= AI_ADDRCONFIG;
+#endif
 				break;
 
 			case 'h':
