$NetBSD: patch-gio_gthreadedresolver.c,v 1.2 2013/06/14 21:04:03 wiz Exp $

--- gio/gthreadedresolver.c.orig	2013-06-09 22:07:09.000000000 +0000
+++ gio/gthreadedresolver.c
@@ -369,6 +369,8 @@ g_resolver_record_type_to_rrtype (GResol
   g_return_val_if_reached (-1);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static GList *
 g_resolver_records_from_res_query (const gchar      *rrname,
                                    gint              rrtype,
@@ -482,6 +484,7 @@ g_resolver_records_from_res_query (const
   else
     return records;
 }
+#pragma GCC diagnostic pop
 
 #elif defined(G_OS_WIN32)
 
