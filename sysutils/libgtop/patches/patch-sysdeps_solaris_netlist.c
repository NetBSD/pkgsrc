$NetBSD: patch-sysdeps_solaris_netlist.c,v 1.1 2016/04/28 22:18:58 jperkin Exp $

Find correct network interfaces.

--- sysdeps/solaris/netlist.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/solaris/netlist.c
@@ -57,7 +57,7 @@ glibtop_get_netlist_s (glibtop *server,
 	
 	for (ksp = kc->kc_chain; ksp; ksp = ksp->ks_next)
 	{
-		if (strcmp(ksp->ks_class, "net") != 0)
+		if (strcmp(ksp->ks_module, "link") != 0)
 			continue;
 
 		g_ptr_array_add(devices, g_strdup(ksp->ks_name));
