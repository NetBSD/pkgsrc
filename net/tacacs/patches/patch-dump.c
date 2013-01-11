$NetBSD: patch-dump.c,v 1.1 2013/01/11 00:03:30 joerg Exp $

--- dump.c.orig	2013-01-10 22:32:13.000000000 +0000
+++ dump.c
@@ -119,8 +119,7 @@ u_char *pak;
 
 
 /* Dump packets originated by a NAS */
-dump_nas_pak(pak)
-u_char *pak;
+void dump_nas_pak(u_char *pak)
 {
     struct authen_start *start;
     struct authen_cont *cont;
@@ -377,8 +376,7 @@ u_char *pak;
 
 /* Dump packets originated by Tacacsd  */
 
-dump_tacacs_pak(pak)
-u_char *pak;
+void dump_tacacs_pak(u_char *pak)
 {
     struct authen_reply *authen;
     struct author_reply *author;
