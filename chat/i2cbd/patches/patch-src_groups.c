$NetBSD: patch-src_groups.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix copy length

--- src/groups.c.orig	2006-05-11 03:44:52.000000000 +0000
+++ src/groups.c
@@ -168,8 +168,8 @@ check_mods(int u_index)
 void
 fill_group_entry(int n, char *name, char *topic, int visibility, int control, int mod, int volume)
 {
-        strlcpy(g_tab[n].name, name, MAX_GROUPLEN);
-        strlcpy(g_tab[n].topic, topic, MAX_TOPICLEN);
+        strlcpy(g_tab[n].name, name, MAX_GROUPLEN+1);
+        strlcpy(g_tab[n].topic, topic, MAX_TOPICLEN+1);
 
         g_tab[n].visibility = visibility;
         g_tab[n].control = control;
