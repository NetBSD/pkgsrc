$NetBSD: patch-spamdyke.h,v 1.2 2018/07/29 08:41:18 schmonz Exp $

Substitute paths.
Remove anonymous inner functions to build with clang.

--- spamdyke.h.orig	2015-04-30 00:53:36.000000000 +0000
+++ spamdyke.h
@@ -104,7 +104,7 @@
 #define STRINGIFY(X)                    _STRINGIFY(X)
 
 #define DEFAULT_REMOTE_IP               "0.0.0.0"
-#define DEFAULT_PATH                    "/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:/var/qmail/bin:/home/vpopmail/bin"
+#define DEFAULT_PATH                    "/bin:/usr/bin:@PREFIX@/bin:@QMAILDIR@/bin:/home/vpopmail/bin"
 #define DEFAULT_NIHDNS_RESOLVER_FILENAME        "/etc/resolv.conf"
 #define DEFAULT_NIHDNS_PORT             53
 #define DEFAULT_TIMEOUT_NIHDNS_TOTAL_SECS       30
@@ -1524,11 +1524,19 @@ struct rejection_data
 #define CONFIG_LOCATION_GLOBAL_FILE             0x02
 #define CONFIG_LOCATION_DIR                     0x10
 
-#define CONFIG_SET_ACTION(CMD)                  ({ int action(struct filter_settings *current_settings, int current_return_value, char *input_value, struct previous_action *history) { CMD; return(current_return_value); } &action; })
-#define CONFIG_ACTION(CMD)                      ({ int action(struct filter_settings *current_settings, int current_return_value) { CMD; return(current_return_value); } &action; })
-#define CONFIG_ACCESSOR_INTEGER(MEMBER)         ({ int *access_integer(struct option_set *current_options) { return(&current_options->MEMBER); } &access_integer; })
-#define CONFIG_ACCESSOR_STRING(MEMBER)          ({ char **access_string(struct option_set *current_options, int current_options_only) { return(&current_options->MEMBER); } &access_string; })
-#define CONFIG_ACCESSOR_STRING_ARRAY(MEMBER)    ({ char ***access_string_array(struct option_set *current_options, int current_options_only) { return(&current_options->MEMBER); } &access_string_array; })
+#define CONFIG_SET_ACTION_PREDEF(NAME, CMD)            static int predef_set_action_ ## NAME(struct filter_settings *current_settings, int current_return_value, char *input_value, struct previous_action *history) { CMD; return(current_return_value); }
+#define CONFIG_ACTION_PREDEF(NAME, CMD)                      static int predef_action_ ## NAME(struct filter_settings *current_settings, int current_return_value) { CMD; return(current_return_value); }
+#define CONFIG_ACCESSOR_INTEGER_PREDEF(MEMBER)         static int *predef_access_integer_ ## MEMBER(struct option_set *current_options) { return(&current_options->MEMBER); }
+#define CONFIG_ACCESSOR_STRING_PREDEF(MEMBER)          static char **predef_access_string_ ## MEMBER(struct option_set *current_options, int current_options_only) { return(&current_options->MEMBER); }
+#define CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(MEMBER)    static char ***predef_access_string_array_ ## MEMBER(struct option_set *current_options, int current_options_only) { return(&current_options->MEMBER); }
+#define CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(ARRAY, MEMBER)          static char **predef_access_string_ ## ARRAY ## _ ## MEMBER(struct option_set *current_options, int current_options_only) { return(&current_options->ARRAY[MEMBER]); }
+
+#define CONFIG_SET_ACTION(NAME, CMD)                  predef_set_action_ ## NAME
+#define CONFIG_ACTION(NAME, CMD)                      predef_action_ ## NAME
+#define CONFIG_ACCESSOR_INTEGER(MEMBER)         predef_access_integer_ ## MEMBER
+#define CONFIG_ACCESSOR_STRING(MEMBER)          predef_access_string_ ## MEMBER
+#define CONFIG_ACCESSOR_STRING_ARRAY(MEMBER)    predef_access_string_array_ ## MEMBER
+#define CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(ARRAY, MEMBER)          predef_access_string_ ## ARRAY ## _ ## MEMBER
 
 #define ES_TYPE_NONE                            0
 #define ES_TYPE_SEND                            1
