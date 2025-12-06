$NetBSD: patch-cgi-bin_collection.modified.cgi,v 1.1 2025/12/06 22:24:28 wiz Exp $

In success case, CGI scripts should return 0, not 1.
https://github.com/httpdss/collectd-web/pull/152

--- cgi-bin/collection.modified.cgi.orig	2025-03-07 22:07:57.000000000 +0000
+++ cgi-bin/collection.modified.cgi
@@ -379,7 +379,7 @@ sub list_hosts_json {
         -Charset      => 'utf-8'
     );
     print STDOUT to_json( $host_ref, { pretty => 1, indent => 2 } );
-    return (1);
+    return (0);
 }    # list_hosts_json
 
 sub _string_to_color {
@@ -480,7 +480,7 @@ sub action_show_host_json
     );
     print STDOUT to_json ([sort (keys %$all_plugins)],
     { pretty => 1, indent => 2 }) . "\n";
-    return (1);
+    return (0);
 } # action_show_host_json
 
 
@@ -775,7 +775,7 @@ sub action_show_plugin_json {
                            year => [@plugin_list_year],
                            decade => [@plugin_list_decade]},
     { pretty => 1, indent => 2 }) . "\n";
-    return (1);
+    return (0);
 }    # action_show_plugin_json
 
 sub action_show_type {
