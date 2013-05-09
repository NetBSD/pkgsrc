$NetBSD: patch-src_command__ip.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_ip.cc.orig	2013-05-03 23:03:23.000000000 +0000
+++ src/command_ip.cc
@@ -45,6 +45,16 @@
 #include "globals.h"
 #include "command_helpers.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 void
 ipv4_filter_parse(const char* address, int value) {
   uint32_t ip_values[4] = { 0, 0, 0, 0 };
@@ -287,17 +297,17 @@ apply_ipv4_filter_dump() {
 
 void
 initialize_command_ip() {
-  CMD2_ANY         ("strings.ip_filter",       tr1::bind(&torrent::option_list_strings, torrent::OPTION_IP_FILTER));
-  CMD2_ANY         ("strings.ip_tos",          tr1::bind(&torrent::option_list_strings, torrent::OPTION_IP_TOS));
+  CMD2_ANY         ("strings.ip_filter",       bind(&torrent::option_list_strings, torrent::OPTION_IP_FILTER));
+  CMD2_ANY         ("strings.ip_tos",          bind(&torrent::option_list_strings, torrent::OPTION_IP_TOS));
 
-  CMD2_ANY_STRING  ("ip_tables.insert_table",  tr1::bind(&apply_ip_tables_insert_table, tr1::placeholders::_2));
-  CMD2_ANY_STRING  ("ip_tables.size_data",     tr1::bind(&apply_ip_tables_size_data, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("ip_tables.get",           tr1::bind(&apply_ip_tables_get, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("ip_tables.add_address",   tr1::bind(&apply_ip_tables_add_address, tr1::placeholders::_2));
-
-  CMD2_ANY         ("ipv4_filter.size_data",   tr1::bind(&apply_ipv4_filter_size_data));
-  CMD2_ANY_STRING  ("ipv4_filter.get",         tr1::bind(&apply_ipv4_filter_get, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("ipv4_filter.add_address", tr1::bind(&apply_ipv4_filter_add_address, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("ipv4_filter.load",        tr1::bind(&apply_ipv4_filter_load, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("ipv4_filter.dump",        tr1::bind(&apply_ipv4_filter_dump));
+  CMD2_ANY_STRING  ("ip_tables.insert_table",  bind(&apply_ip_tables_insert_table, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING  ("ip_tables.size_data",     bind(&apply_ip_tables_size_data, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("ip_tables.get",           bind(&apply_ip_tables_get, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("ip_tables.add_address",   bind(&apply_ip_tables_add_address, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY         ("ipv4_filter.size_data",   bind(&apply_ipv4_filter_size_data));
+  CMD2_ANY_STRING  ("ipv4_filter.get",         bind(&apply_ipv4_filter_get, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("ipv4_filter.add_address", bind(&apply_ipv4_filter_add_address, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("ipv4_filter.load",        bind(&apply_ipv4_filter_load, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("ipv4_filter.dump",        bind(&apply_ipv4_filter_dump));
 }
