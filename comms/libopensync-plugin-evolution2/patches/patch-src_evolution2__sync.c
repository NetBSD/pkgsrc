$NetBSD: patch-src_evolution2__sync.c,v 1.1 2013/05/25 23:41:24 joerg Exp $

--- src/evolution2_sync.c.orig	2007-03-27 11:49:55.000000000 +0000
+++ src/evolution2_sync.c
@@ -121,8 +121,6 @@ static void *evo2_initialize(OSyncMember
 	char *configdata = NULL;
 	int configsize = 0;
 	
-	g_type_init();
-	
 	evo_environment *env = g_malloc0(sizeof(evo_environment));
 
 	if (!osync_member_get_config_or_default(member, &configdata, &configsize, error))
