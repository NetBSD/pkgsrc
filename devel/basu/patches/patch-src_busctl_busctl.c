$NetBSD: patch-src_busctl_busctl.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/busctl/busctl.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/busctl/busctl.c
@@ -57,11 +57,11 @@ static usec_t arg_timeout = 0;
 #define NAME_IS_ACTIVATABLE INT_TO_PTR(2)
 
 static int bus_log_parse_error(int r) {
-        return log_error_errno(r, "Failed to parse bus message: %m");
+        return log_error_errno(r, "Failed to parse bus message");
 }
 
 static int bus_log_create_error(int r) {
-        return log_error_errno(r, "Failed to create bus message: %m");
+        return log_error_errno(r, "Failed to create bus message");
 }
 
 static int acquire_bus(bool set_monitor, sd_bus **ret) {
@@ -70,33 +70,33 @@ static int acquire_bus(bool set_monitor,
 
         r = sd_bus_new(&bus);
         if (r < 0)
-                return log_error_errno(r, "Failed to allocate bus: %m");
+                return log_error_errno(r, "Failed to allocate bus");
 
         if (set_monitor) {
                 r = sd_bus_set_monitor(bus, true);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to set monitor mode: %m");
+                        return log_error_errno(r, "Failed to set monitor mode");
 
                 r = sd_bus_negotiate_creds(bus, true, _SD_BUS_CREDS_ALL);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to enable credentials: %m");
+                        return log_error_errno(r, "Failed to enable credentials");
 
                 r = sd_bus_negotiate_timestamp(bus, true);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to enable timestamps: %m");
+                        return log_error_errno(r, "Failed to enable timestamps");
 
                 r = sd_bus_negotiate_fds(bus, true);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to enable fds: %m");
+                        return log_error_errno(r, "Failed to enable fds");
         }
 
         r = sd_bus_set_bus_client(bus, true);
         if (r < 0)
-                return log_error_errno(r, "Failed to set bus client: %m");
+                return log_error_errno(r, "Failed to set bus client");
 
         r = sd_bus_set_watch_bind(bus, arg_watch_bind);
         if (r < 0)
-                return log_error_errno(r, "Failed to set watch-bind setting to '%s': %m", yes_no(arg_watch_bind));
+                return log_error_errno(r, "Failed to set watch-bind setting to '%s'", yes_no(arg_watch_bind));
 
         if (arg_address)
                 r = sd_bus_set_address(bus, arg_address);
@@ -118,11 +118,11 @@ static int acquire_bus(bool set_monitor,
                 }
         }
         if (r < 0)
-                return log_error_errno(r, "Failed to set address: %m");
+                return log_error_errno(r, "Failed to set address");
 
         r = sd_bus_start(bus);
         if (r < 0)
-                return log_error_errno(r, "Failed to connect to bus: %m");
+                return log_error_errno(r, "Failed to connect to bus");
 
         *ret = TAKE_PTR(bus);
 
@@ -151,7 +151,7 @@ static int list_bus_names(int argc, char
 
         r = sd_bus_list_names(bus, (arg_acquired || arg_unique) ? &acquired : NULL, arg_activatable ? &activatable : NULL);
         if (r < 0)
-                return log_error_errno(r, "Failed to list names: %m");
+                return log_error_errno(r, "Failed to list names");
 
         names = hashmap_new(&string_hash_ops);
         if (!names)
@@ -162,7 +162,7 @@ static int list_bus_names(int argc, char
 
                 r = hashmap_put(names, *i, NAME_IS_ACQUIRED);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to add to hashmap: %m");
+                        return log_error_errno(r, "Failed to add to hashmap");
         }
 
         STRV_FOREACH(i, activatable) {
@@ -170,7 +170,7 @@ static int list_bus_names(int argc, char
 
                 r = hashmap_put(names, *i, NAME_IS_ACTIVATABLE);
                 if (r < 0 && r != -EEXIST)
-                        return log_error_errno(r, "Failed to add to hashmap: %m");
+                        return log_error_errno(r, "Failed to add to hashmap");
         }
 
         merged = new(char*, hashmap_size(names) + 1);
@@ -496,7 +496,7 @@ static int tree(int argc, char **argv, v
 
                 r = sd_bus_list_names(bus, &names, NULL);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to get name list: %m");
+                        return log_error_errno(r, "Failed to get name list");
 
                 STRV_FOREACH(i, names) {
                         int q;
@@ -1180,7 +1180,7 @@ static int monitor(int argc, char **argv
 
         r = sd_bus_get_unique_name(bus, &unique_name);
         if (r < 0)
-                return log_error_errno(r, "Failed to get unique name: %m");
+                return log_error_errno(r, "Failed to get unique name");
 
         log_info("Monitoring bus message stream.");
 
@@ -1189,7 +1189,7 @@ static int monitor(int argc, char **argv
 
                 r = sd_bus_process(bus, &m);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to process bus: %m");
+                        return log_error_errno(r, "Failed to process bus");
 
                 if (!is_monitor) {
                         const char *name;
@@ -1200,7 +1200,7 @@ static int monitor(int argc, char **argv
 
                         r = sd_bus_message_read(m, "s", &name);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to read lost name: %m");
+                                return log_error_errno(r, "Failed to read lost name");
 
                         if (streq(name, unique_name))
                                 is_monitor = true;
@@ -1225,7 +1225,7 @@ static int monitor(int argc, char **argv
 
                 r = sd_bus_wait(bus, (uint64_t) -1);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to wait for bus: %m");
+                        return log_error_errno(r, "Failed to wait for bus");
         }
 }
 
@@ -1279,7 +1279,7 @@ static int status(int argc, char **argv,
         }
 
         if (r < 0)
-                return log_error_errno(r, "Failed to get credentials: %m");
+                return log_error_errno(r, "Failed to get credentials");
 
         bus_creds_dump(creds, NULL, false);
         return 0;
@@ -1318,7 +1318,7 @@ static int message_append_cmdline(sd_bus
 
                         r = parse_boolean(v);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as boolean: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as boolean", v);
 
                         r = sd_bus_message_append_basic(m, t, &r);
                         break;
@@ -1328,7 +1328,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atou8(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as byte (unsigned 8bit integer): %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as byte (unsigned 8bit integer)", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1339,7 +1339,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atoi16(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as signed 16bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as signed 16bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1350,7 +1350,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atou16(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as unsigned 16bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as unsigned 16bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1361,7 +1361,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atoi32(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as signed 32bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as signed 32bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1372,7 +1372,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atou32(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as unsigned 32bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as unsigned 32bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1383,7 +1383,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atoi64(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as signed 64bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as signed 64bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1394,7 +1394,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atou64(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as unsigned 64bit integer: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as unsigned 64bit integer", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1405,7 +1405,7 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atod(v, &z);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' as double precision floating point: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' as double precision floating point", v);
 
                         r = sd_bus_message_append_basic(m, t, &z);
                         break;
@@ -1424,11 +1424,11 @@ static int message_append_cmdline(sd_bus
 
                         r = safe_atou32(v, &n);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse '%s' number of array entries: %m", v);
+                                return log_error_errno(r, "Failed to parse '%s' number of array entries", v);
 
                         r = signature_element_length(signature, &k);
                         if (r < 0)
-                                return log_error_errno(r, "Invalid array signature: %m");
+                                return log_error_errno(r, "Invalid array signature");
 
                         {
                                 unsigned i;
@@ -1474,7 +1474,7 @@ static int message_append_cmdline(sd_bus
 
                         r = signature_element_length(signature, &k);
                         if (r < 0)
-                                return log_error_errno(r, "Invalid struct/dict entry signature: %m");
+                                return log_error_errno(r, "Invalid struct/dict entry signature");
 
                         {
                                 char s[k-1];
@@ -1662,7 +1662,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_unsigned(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform byte: %m");
+                        return log_error_errno(r, "Failed to transform byte");
 
                 break;
         }
@@ -1676,7 +1676,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_boolean(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform boolean: %m");
+                        return log_error_errno(r, "Failed to transform boolean");
 
                 break;
         }
@@ -1690,7 +1690,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_integer(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform int16: %m");
+                        return log_error_errno(r, "Failed to transform int16");
 
                 break;
         }
@@ -1704,7 +1704,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_unsigned(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform uint16: %m");
+                        return log_error_errno(r, "Failed to transform uint16");
 
                 break;
         }
@@ -1718,7 +1718,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_integer(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform int32: %m");
+                        return log_error_errno(r, "Failed to transform int32");
 
                 break;
         }
@@ -1732,7 +1732,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_unsigned(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform uint32: %m");
+                        return log_error_errno(r, "Failed to transform uint32");
 
                 break;
         }
@@ -1746,7 +1746,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_integer(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform int64: %m");
+                        return log_error_errno(r, "Failed to transform int64");
 
                 break;
         }
@@ -1760,7 +1760,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_unsigned(&v, b);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform uint64: %m");
+                        return log_error_errno(r, "Failed to transform uint64");
 
                 break;
         }
@@ -1774,7 +1774,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_real(&v, d);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform double: %m");
+                        return log_error_errno(r, "Failed to transform double");
 
                 break;
         }
@@ -1790,7 +1790,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_string(&v, s);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform double: %m");
+                        return log_error_errno(r, "Failed to transform double");
 
                 break;
         }
@@ -1802,7 +1802,7 @@ static int json_transform_one(sd_bus_mes
 
                 r = json_variant_new_null(&v);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to transform fd: %m");
+                        return log_error_errno(r, "Failed to transform fd");
 
                 break;
 
@@ -1910,7 +1910,7 @@ static int call(int argc, char **argv, v
         if (!arg_expect_reply) {
                 r = sd_bus_send(bus, m, NULL);
                 if (r < 0)
-                        return log_error_errno(r, "Failed to send message: %m");
+                        return log_error_errno(r, "Failed to send message");
 
                 return 0;
         }
@@ -2227,7 +2227,7 @@ static int parse_argv(int argc, char *ar
                 case ARG_EXPECT_REPLY:
                         r = parse_boolean(optarg);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --expect-reply= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --expect-reply= parameter '%s'", optarg);
 
                         arg_expect_reply = r;
                         break;
@@ -2235,7 +2235,7 @@ static int parse_argv(int argc, char *ar
                 case ARG_AUTO_START:
                         r = parse_boolean(optarg);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --auto-start= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --auto-start= parameter '%s'", optarg);
 
                         arg_auto_start = r;
                         break;
@@ -2243,7 +2243,7 @@ static int parse_argv(int argc, char *ar
                 case ARG_ALLOW_INTERACTIVE_AUTHORIZATION:
                         r = parse_boolean(optarg);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --allow-interactive-authorization= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --allow-interactive-authorization= parameter '%s'", optarg);
 
                         arg_allow_interactive_authorization = r;
                         break;
@@ -2251,14 +2251,14 @@ static int parse_argv(int argc, char *ar
                 case ARG_TIMEOUT:
                         r = parse_sec(optarg, &arg_timeout);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --timeout= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --timeout= parameter '%s'", optarg);
 
                         break;
 
                 case ARG_AUGMENT_CREDS:
                         r = parse_boolean(optarg);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --augment-creds= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --augment-creds= parameter '%s'", optarg);
 
                         arg_augment_creds = r;
                         break;
@@ -2266,7 +2266,7 @@ static int parse_argv(int argc, char *ar
                 case ARG_WATCH_BIND:
                         r = parse_boolean(optarg);
                         if (r < 0)
-                                return log_error_errno(r, "Failed to parse --watch-bind= parameter '%s': %m", optarg);
+                                return log_error_errno(r, "Failed to parse --watch-bind= parameter '%s'", optarg);
 
                         arg_watch_bind = r;
                         break;
