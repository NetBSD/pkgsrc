$NetBSD: patch-src_FmChmod.c,v 1.1 2025/04/11 01:49:11 nia Exp $

Modern systems might have slightly longer usernames.

--- src/FmChmod.c.orig	2025-04-11 00:08:50.660878438 +0000
+++ src/FmChmod.c
@@ -45,7 +45,7 @@ typedef struct
  {
     Widget dialog, w_owner, w_group;
     String file, directory;
-    char owner[10], group[10];
+    char owner[32], group[32];
     uid_t owner_id;
     gid_t group_id;
     ChmodItem items[3][3];
