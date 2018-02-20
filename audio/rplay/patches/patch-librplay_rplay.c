$NetBSD: patch-librplay_rplay.c,v 1.1 2018/02/20 08:35:52 dholland Exp $

Use standard headers.

--- librplay/rplay.c~	1999-03-10 07:57:56.000000000 +0000
+++ librplay/rplay.c
@@ -29,6 +29,7 @@
 #include <sys/param.h>
 #include <netdb.h>
 #include <string.h>
+#include <time.h>
 #include <arpa/inet.h>
 
 #ifdef __STDC__
