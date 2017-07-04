$NetBSD: patch-runtime_lookup.c,v 1.4 2017/07/04 13:31:16 fhajny Exp $

Handle Darwin's pthread_setname_np().

--- runtime/lookup.c.orig	2017-06-25 11:46:08.000000000 +0000
+++ runtime/lookup.c
@@ -958,10 +958,12 @@ lookupTableDefProcessCnf(struct cnfobj *
 	strcpy(reloader_thd_name, reloader_prefix);
 	strcpy(reloader_thd_name + strlen(reloader_prefix), (char*) lu->name);
 	reloader_thd_name[thd_name_len - 1] = '\0';
-  #ifndef __APPLE__
-     pthread_setname_np(lu->reloader, reloader_thd_name);
-  #else
+  #if defined(__NetBSD__)
+     pthread_setname_np(lu->reloader, "%s", reloader_thd_name);
+  #elif defined(__APPLE__)
      pthread_setname_np(reloader_thd_name); // must check
+  #else
+     pthread_setname_np(lu->reloader, reloader_thd_name);
   #endif
 #endif
 	CHKiRet(lookupReadFile(lu->self, lu->name, lu->filename));
