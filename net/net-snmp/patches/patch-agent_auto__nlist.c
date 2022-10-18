$NetBSD: patch-agent_auto__nlist.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/auto_nlist.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/auto_nlist.c
@@ -67,7 +67,7 @@ auto_nlist_value(const char *string)
         it->nl[0].n_name = (char *) malloc(strlen(string) + 2);
 #if defined(aix4) || defined(aix5) || defined(aix6) || defined(aix7)
         strcpy(it->nl[0].n_name, string);
-        it->nl[0].n_name[strlen(string)+1] = '\0';
+        /* it->nl[0].n_name[strlen(string)+1] = '\0'; */
 #elif defined(freebsd9)
         sprintf(__DECONST(char*, it->nl[0].n_name), "_%s", string);
 #else
