$NetBSD: patch-sql-common_client__plugin.c,v 1.1 2014/11/25 14:54:22 joerg Exp $

--- sql-common/client_plugin.c.orig	2014-11-21 12:41:46.000000000 +0000
+++ sql-common/client_plugin.c
@@ -179,6 +179,18 @@ err1:
   return NULL;
 }
 
+static struct st_mysql_client_plugin *
+add_plugin_no_args(MYSQL *mysql, struct st_mysql_client_plugin *plugin, void *dlhandle,
+           int argc, ...)
+{
+  va_list args;
+  struct st_mysql_client_plugin *rv;
+  va_start(args, argc);
+  rv = add_plugin(mysql, plugin, dlhandle, argc, args);
+  va_end(args);
+  return rv;
+}
+
 /**
   Loads plugins which are specified in the environment variable
   LIBMYSQL_PLUGINS.
@@ -249,7 +261,7 @@ int mysql_client_plugin_init()
   pthread_mutex_lock(&LOCK_load_client_plugin);
 
   for (builtin= mysql_client_builtins; *builtin; builtin++)
-    add_plugin(&mysql, *builtin, 0, 0, 0);
+    add_plugin_no_args(&mysql, *builtin, 0, 0);
 
   pthread_mutex_unlock(&LOCK_load_client_plugin);
 
@@ -307,7 +319,7 @@ mysql_client_register_plugin(MYSQL *mysq
     plugin= NULL;
   }
   else
-    plugin= add_plugin(mysql, plugin, 0, 0, 0);
+    plugin= add_plugin_no_args(mysql, plugin, 0, 0);
 
   pthread_mutex_unlock(&LOCK_load_client_plugin);
   return plugin;
