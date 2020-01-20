$NetBSD: patch-rts_idris__net.c,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build on NetBSD where byteorder(3) functions don't become
available just by including <netinet/in.h>.

--- rts/idris_net.c.orig	2020-01-20 15:18:01.972754256 +0000
+++ rts/idris_net.c
@@ -1,6 +1,7 @@
 // C-Side of the Idris network library
 // (C) Simon Fowler, 2014
 // MIT Licensed. Have fun!
+#define _XOPEN_SOURCE 600
 #include "idris_net.h"
 #include <errno.h>
 #include <stdbool.h>
