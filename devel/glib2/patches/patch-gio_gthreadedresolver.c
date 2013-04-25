$NetBSD: patch-gio_gthreadedresolver.c,v 1.1 2013/04/25 12:10:48 joerg Exp $

--- gio/gthreadedresolver.c.orig	2013-04-23 20:38:28.000000000 +0000
+++ gio/gthreadedresolver.c
@@ -369,6 +369,8 @@ g_resolver_record_type_to_rrtype (GResol
   g_return_val_if_reached (-1);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static GList *
 g_resolver_records_from_res_query (const gchar      *rrname,
                                    gint              rrtype,
@@ -474,6 +476,7 @@ g_resolver_records_from_res_query (const
 
     return records;
 }
+#pragma GCC diagnostic pop
 
 #elif defined(G_OS_WIN32)
 
