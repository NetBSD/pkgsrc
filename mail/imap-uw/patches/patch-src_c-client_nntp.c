$NetBSD: patch-src_c-client_nntp.c,v 1.1 2025/11/10 20:49:43 vins Exp $

time.h required for time(3). 

--- src/c-client/nntp.c.orig	2025-11-10 21:08:16.261164736 +0000
+++ src/c-client/nntp.c
@@ -29,6 +29,7 @@
 
 #include <ctype.h>
 #include <stdio.h>
+#include <time.h>
 #include "c-client.h"
 #include "newsrc.h"
 #include "netmsg.h"
