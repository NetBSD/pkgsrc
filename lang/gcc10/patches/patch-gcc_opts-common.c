$NetBSD: patch-gcc_opts-common.c,v 1.1 2024/04/01 14:33:57 js Exp $

--- gcc/opts-common.c.orig	2023-07-07 07:08:19.000000000 +0000
+++ gcc/opts-common.c
@@ -1808,7 +1808,7 @@ void prepend_xassembler_to_collect_as_op
     }
 }
 
-jobserver_info::jobserver_info ()
+jobserver_info::jobserver_info () : rfd(-1), wfd(-1), is_active(false)
 {
   /* Traditionally, GNU make uses opened pipes for jobserver-auth,
     e.g. --jobserver-auth=3,4.
