$NetBSD: patch-support_rpcping_rpcping.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- support/rpcping/rpcping.c~	1998-07-31 21:20:14.000000000 +0000
+++ support/rpcping/rpcping.c
@@ -42,6 +42,8 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <signal.h>
 #include <rpc/rpc.h>
 #include <rpc/pmap_prot.h>
