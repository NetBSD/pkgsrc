$NetBSD: patch-src_plugins_relay_api_relay-api-msg.c,v 1.1 2024/12/16 10:55:22 jperkin Exp $

illumos does not have tm_gmtoff.

--- src/plugins/relay/api/relay-api-msg.c.orig	2024-12-16 10:46:41.984837031 +0000
+++ src/plugins/relay/api/relay-api-msg.c
@@ -55,6 +55,18 @@
         cJSON_Create##__json_type (                                     \
             weechat_hdata_##__var_type (hdata, pointer, __var_name)));
 
+#if defined(__illumos__)
+#define MSG_ADD_HDATA_TIME_USEC(__json_name,                            \
+                                __var_name, __var_name_usec)            \
+    time_value = weechat_hdata_time (hdata, pointer, __var_name);       \
+    local_time = localtime (&time_value);                               \
+    tv.tv_sec = mktime (local_time);                                    \
+    tv.tv_usec = weechat_hdata_integer (hdata, pointer,                 \
+                                        __var_name_usec);               \
+    weechat_util_strftimeval (str_time, sizeof (str_time),              \
+                              "%FT%T.%fZ", &tv);                        \
+    MSG_ADD_STR_BUF(__json_name, str_time);
+#else
 #define MSG_ADD_HDATA_TIME_USEC(__json_name,                            \
                                 __var_name, __var_name_usec)            \
     time_value = weechat_hdata_time (hdata, pointer, __var_name);       \
@@ -67,6 +79,7 @@
     weechat_util_strftimeval (str_time, sizeof (str_time),              \
                               "%FT%T.%fZ", &tv);                        \
     MSG_ADD_STR_BUF(__json_name, str_time);
+#endif
 
 #define MSG_ADD_HDATA_STR(__json_name, __var_name)                      \
     ptr_string = weechat_hdata_string (hdata, pointer, __var_name);     \
