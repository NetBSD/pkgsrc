$NetBSD: patch-net__read.c,v 1.1 2026/06/20 10:19:39 nia Exp $

Need to include <strings.h> for bcopy(3).

--- net_read.c.orig	2026-06-20 10:16:39.238942032 +0000
+++ net_read.c
@@ -74,6 +74,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <err.h>
 
 #include <pcap.h>
