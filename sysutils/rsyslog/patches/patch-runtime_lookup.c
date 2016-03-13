$NetBSD: patch-runtime_lookup.c,v 1.1 2016/03/13 08:15:59 tnn Exp $

--- runtime/lookup.c.orig	2016-03-07 06:47:55.000000000 +0000
+++ runtime/lookup.c
@@ -926,8 +926,12 @@ lookupTableDefProcessCnf(struct cnfobj *
 	strcpy(reloader_thd_name, reloader_prefix);
 	strcpy(reloader_thd_name + strlen(reloader_prefix), (char*) lu->name);
 	reloader_thd_name[thd_name_len - 1] = '\0';
+#if defined(__NetBSD__)
+	pthread_setname_np(lu->reloader, "%s", reloader_thd_name);
+#else
 	pthread_setname_np(lu->reloader, reloader_thd_name);
 #endif
+#endif
 	CHKiRet(lookupReadFile(lu->self, lu->name, lu->filename));
 	DBGPRINTF("lookup table '%s' loaded from file '%s'\n", lu->name, lu->filename);
 
