$NetBSD: patch-src_netstat.c,v 1.1 2016/04/18 12:14:29 jperkin Exp $

Fix SunOS build, from OpenIndiana.

--- src/netstat.c.orig	2009-05-20 00:56:41.000000000 +0000
+++ src/netstat.c
@@ -112,9 +112,15 @@ netstat_get_active_option (Netinfo * net
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->routing))) {
 		/* Works for Solaris and Linux */
 		if (netinfo_is_ipv6_enable ()) {
+#ifdef __sun
+			option = g_strdup ("-rn -f inet -f inet6");
+		} else {
+			option = g_strdup ("-rn -f inet");
+#else
 			option = g_strdup ("-rn -A inet -A inet6");
 		} else {
 			option = g_strdup ("-rn -A inet");
+#endif
 		}
 
 		if (netinfo->stbar_text)
@@ -125,7 +131,7 @@ netstat_get_active_option (Netinfo * net
 		/* Only works for Solaris */
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	    	option = g_strdup ("-a -f inet -ln");
-#else
+#elif defined(__linux)
 		if (netinfo_is_ipv6_enable ()) {
 			option = g_strdup ("-A inet -A inet6 -ln");
 		} else {
@@ -541,7 +547,11 @@ netstat_route_tree_insert (GtkTreeView *
 		gtk_list_store_set (GTK_LIST_STORE (model), &iter,
 					0, data.destination,
 					1, data.gateway,
+#ifdef __sun
+					2, NULL,
+#else
 					2, data.netmask,
+#endif
 					3, data.iface, -1);
 
 		gtk_tree_view_set_model (widget, model);
@@ -562,7 +572,7 @@ strip_route_line (gchar * line, netstat_
 	gchar **items;
 #endif
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__sun)
 	count = sscanf (line, NETSTAT_ROUTE_FORMAT,
 			data->destination,
 			data->gateway, flags,
