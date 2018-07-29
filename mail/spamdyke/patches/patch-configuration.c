$NetBSD: patch-configuration.c,v 1.1 2018/07/29 08:41:18 schmonz Exp $

Remove anonymous inner functions to build with clang.

--- configuration.c.orig	2018-07-08 20:20:10.283510612 +0000
+++ configuration.c
@@ -359,6 +359,140 @@ int copy_base_options(struct filter_sett
  * Return value:
  *   exit value for main()
  */
+CONFIG_ACTION_PREDEF(smtp_auth_level, if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_LEVEL_MASK) != SMTP_AUTH_LEVEL_VALUE_NONE) && (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM)) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM)
+CONFIG_ACTION_PREDEF(smtp_auth_verification, if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_SET_MASK) == SMTP_AUTH_SET_VALUE_UNSET) && (current_settings->current_options->smtp_auth_command != NULL) && (current_settings->current_options->smtp_auth_command[0] != NULL)) { current_settings->current_options->smtp_auth_level = SMTP_AUTH_LEVEL_VALUE_ON_DEMAND | SMTP_AUTH_SET_VALUE_SET; if (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM; })
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_sender)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_sender_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_sender)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_sender_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(smtp_auth_command)
+CONFIG_ACCESSOR_INTEGER_PREDEF(smtp_auth_level)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_certificate_file)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_cipher_list)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_dhparams_file)
+CONFIG_ACCESSOR_INTEGER_PREDEF(tls_level)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_privatekey_file)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_privatekey_password)
+CONFIG_ACCESSOR_STRING_PREDEF(tls_privatekey_password_file)
+CONFIG_ACCESSOR_STRING_PREDEF(run_user)
+CONFIG_ACCESSOR_INTEGER_PREDEF(relay_level)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(rhsbl_fqdn)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(rhsbl_fqdn_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(rhswl_fqdn)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(rhswl_fqdn_file)
+CONFIG_ACCESSOR_STRING_PREDEF(local_server_name)
+CONFIG_ACCESSOR_STRING_PREDEF(local_server_name_command)
+CONFIG_ACCESSOR_STRING_PREDEF(local_server_name_file)
+CONFIG_ACCESSOR_INTEGER_PREDEF(timeout_command)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_ip)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_ip_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_rdns_keyword)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_rdns_keyword_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_rdns_keyword)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_rdns_keyword_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(relay_ip)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(relay_ip_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_ip)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_ip_file)
+CONFIG_ACCESSOR_INTEGER_PREDEF(log_level)
+CONFIG_ACCESSOR_INTEGER_PREDEF(check_earlytalker)
+CONFIG_ACCESSOR_INTEGER_PREDEF(configuration_dir_search)
+CONFIG_ACCESSOR_INTEGER_PREDEF(filter_level)
+CONFIG_ACCESSOR_INTEGER_PREDEF(graylist_level)
+CONFIG_ACCESSOR_INTEGER_PREDEF(graylist_max_secs)
+CONFIG_ACCESSOR_INTEGER_PREDEF(graylist_min_secs)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_attempts_primary)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_attempts_total)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_level)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_query_type_a)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_query_type_mx)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_query_type_ptr)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_query_type_rbl)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_spoof)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_tcp)
+CONFIG_ACCESSOR_INTEGER_PREDEF(nihdns_timeout_total_secs_parameter)
+CONFIG_ACCESSOR_INTEGER_PREDEF(timeout_connection)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(config_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(configuration_dir)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(dnsrbl_fqdn)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(dnsrbl_fqdn_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(dnsrwl_fqdn)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(dnsrwl_fqdn_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_dir)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_exception_ip)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_exception_ip_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_exception_rdns)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_exception_rdns_dir)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(graylist_exception_rdns_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(nihdns_primary_server_list)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(nihdns_resolv_conf)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(nihdns_secondary_server_list)
+CONFIG_ACCESSOR_STRING_PREDEF(log_dir)
+CONFIG_ACCESSOR_STRING_PREDEF(test_smtp_auth_password)
+CONFIG_ACCESSOR_STRING_PREDEF(test_smtp_auth_username)
+CONFIG_SET_ACTION_PREDEF(loglevel, if (current_settings->current_options->log_level == 0) current_settings->current_options->log_level = LOG_LEVEL_ERROR)
+CONFIG_SET_ACTION_PREDEF(relay_level_unset, if (current_settings->current_options->relay_level == RELAY_LEVEL_UNSET) current_settings->current_options->relay_level = RELAY_LEVEL_NORMAL;)
+CONFIG_SET_ACTION_PREDEF(strlen_policy_location, current_settings->current_options->strlen_policy_location = (current_settings->current_options->policy_location != NULL) ? strlen(current_settings->current_options->policy_location) : 0)
+CONFIG_SET_ACTION_PREDEF(strlen_tls_privatekey_password, current_settings->current_options->strlen_tls_privatekey_password = (current_settings->current_options->tls_privatekey_password != NULL) ? strlen(current_settings->current_options->tls_privatekey_password) : 0)
+CONFIG_SET_ACTION_PREDEF(usage_brief, usage(current_settings, USAGE_LEVEL_BRIEF, NULL))
+CONFIG_SET_ACTION_PREDEF(usage_long, usage(current_settings, USAGE_LEVEL_LONG, NULL))
+CONFIG_SET_ACTION_PREDEF(usage_short, usage(current_settings, USAGE_LEVEL_SHORT, NULL))
+CONFIG_ACCESSOR_INTEGER_PREDEF(log_target)
+CONFIG_ACCESSOR_INTEGER_PREDEF(max_rcpt_to)
+CONFIG_ACCESSOR_STRING_PREDEF(policy_location)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(qmail_morercpthosts_cdb)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(qmail_rcpthosts_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_rdns_dir)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_rdns)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_rdns_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(relay_rdns)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(relay_rdns_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_rdns_dir)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_rdns)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_rdns_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_recipient)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(blacklist_recipient_file)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_recipient)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(whitelist_recipient_file)
+CONFIG_ACCESSOR_INTEGER_PREDEF(check_rdns_exist)
+CONFIG_ACCESSOR_INTEGER_PREDEF(check_ip_in_rdns_cc)
+CONFIG_ACCESSOR_INTEGER_PREDEF(reject_recipient)
+CONFIG_ACCESSOR_INTEGER_PREDEF(reject_sender)
+CONFIG_ACCESSOR_INTEGER_PREDEF(check_rdns_resolve)
+CONFIG_ACCESSOR_STRING_ARRAY_PREDEF(recipient_validation_command)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SMTP_AUTH_FAILURE)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SMTP_AUTH_UNKNOWN)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RBL)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_EARLYTALKER)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RDNS_MISSING)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_GRAYLISTED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_HEADER_BLACKLISTED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_BLACKLIST_IP)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_IP_IN_NAME_CC)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_IP_IN_NAME)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RCPT_TO_LOCAL)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RCPT_TO)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_BLACKLIST_NAME)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RECIPIENT_BLACKLISTED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_INVALID_RECIPIENT)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_IDENTICAL_FROM_TO)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_UNAVAILABLE_RECIPIENT)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_UNCONDITIONAL)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RELAYING_DENIED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RHSBL)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SENDER_NOT_AUTH)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SENDER_BLACKLISTED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SENDER_NO_MX)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_SENDER_NOT_LOCAL)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_AUTH_REQUIRED)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_TIMEOUT)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, FAILURE_TLS)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_RDNS_RESOLVE)
+CONFIG_ACCESSOR_STRING_ARRAY_MEMBER_PREDEF(rejection_text, REJECTION_ZERO_RECIPIENTS)
+
+static char ***predef_access_string_array_blacklist_header(struct option_set *current_options, int current_options_only) { return(current_options_only ? NULL : &current_options->container->blacklist_header); }
+static char ***predef_access_string_array_blacklist_header_file(struct option_set *current_options, int current_options_only) { return(current_options_only ? NULL : &current_options->container->blacklist_header_file); }
+
 int prepare_settings(int argc, char *argv[], char *envp[], int (*main_function)(struct filter_settings *, int, char **))
   {
   int return_value;
@@ -706,7 +840,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_CONFIG_TEST,
       FILTER_GRACE_NONE,
       NULL,
-      CONFIG_SET_ACTION(if (current_settings->current_options->log_level == 0) current_settings->current_options->log_level = LOG_LEVEL_ERROR),
+      CONFIG_SET_ACTION(loglevel, if (current_settings->current_options->log_level == 0) current_settings->current_options->log_level = LOG_LEVEL_ERROR),
       NULL,
       NULL,
       "Tests the configuration as much as possible and reports any errors that can be discovered without actually accepting an incoming message."
@@ -1436,7 +1570,7 @@ int prepare_settings(int argc, char *arg
       { "header-blacklist-entry", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string_array = ({ char ***access_string_array(struct option_set *current_options, int current_options_only) { return(current_options_only ? NULL : &current_options->container->blacklist_header); } &access_string_array; }) },
+      { .get_string_array = predef_access_string_array_blacklist_header },
       { .max_strlen = 0 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -1453,7 +1587,7 @@ int prepare_settings(int argc, char *arg
       { "header-blacklist-file", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string_array = ({ char ***access_string_array(struct option_set *current_options, int current_options_only) { return(current_options_only ? NULL : &current_options->container->blacklist_header_file); } &access_string_array; }) },
+      { .get_string_array = predef_access_string_array_blacklist_header_file },
       { .max_strlen = 0 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -1475,7 +1609,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_ERROR,
       FILTER_GRACE_NONE,
       NULL,
-      CONFIG_SET_ACTION(usage(current_settings, USAGE_LEVEL_BRIEF, NULL)),
+      CONFIG_SET_ACTION(usage_brief, usage(current_settings, USAGE_LEVEL_BRIEF, NULL)),
       NULL,
       NULL,
       "Displays a (shorter) option summary and exits."
@@ -1802,7 +1936,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_ERROR,
       FILTER_GRACE_NONE,
       NULL,
-      CONFIG_SET_ACTION(usage(current_settings, USAGE_LEVEL_LONG, NULL)),
+      CONFIG_SET_ACTION(usage_long, usage(current_settings, USAGE_LEVEL_LONG, NULL)),
       NULL,
       NULL,
       "Displays this help screen and exits."
@@ -1819,7 +1953,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
       NULL,
-      CONFIG_SET_ACTION(current_settings->current_options->strlen_policy_location = (current_settings->current_options->policy_location != NULL) ? strlen(current_settings->current_options->policy_location) : 0),
+      CONFIG_SET_ACTION(strlen_policy_location, current_settings->current_options->strlen_policy_location = (current_settings->current_options->policy_location != NULL) ? strlen(current_settings->current_options->policy_location) : 0),
       NULL,
       "URL",
       "Append URL to the rejection message to explain why the rejection occurred. NOTE: most servers hide rejection messages from their users and most users don't read bounce messages."
@@ -1837,7 +1971,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
       &config_test_cdb,
-      CONFIG_SET_ACTION(if (current_settings->current_options->relay_level == RELAY_LEVEL_UNSET) current_settings->current_options->relay_level = RELAY_LEVEL_NORMAL;),
+      CONFIG_SET_ACTION(relay_level_unset, if (current_settings->current_options->relay_level == RELAY_LEVEL_UNSET) current_settings->current_options->relay_level = RELAY_LEVEL_NORMAL;),
       NULL,
       "CDB",
       "Search CDB to determine if mail for a domain is accepted here. NOTE: In order for recipient validation to work correctly, spamdyke needs to use the same input"
@@ -1855,7 +1989,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
       &config_test_qmail_option,
-      CONFIG_SET_ACTION(if (current_settings->current_options->relay_level == RELAY_LEVEL_UNSET) current_settings->current_options->relay_level = RELAY_LEVEL_NORMAL;),
+      CONFIG_SET_ACTION(relay_level_unset, if (current_settings->current_options->relay_level == RELAY_LEVEL_UNSET) current_settings->current_options->relay_level = RELAY_LEVEL_NORMAL;),
       NULL,
       "FILE",
       "Search FILE to determine if mail for a domain is accepted here. NOTE: In order for recipient validation to work correctly, spamdyke needs to use the same input"
@@ -2196,7 +2330,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-auth-failure", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SMTP_AUTH_FAILURE]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SMTP_AUTH_FAILURE) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2213,7 +2347,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-auth-unknown", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SMTP_AUTH_UNKNOWN]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SMTP_AUTH_UNKNOWN) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2231,7 +2365,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-dns-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RBL]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RBL) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2249,7 +2383,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-earlytalker", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_EARLYTALKER]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_EARLYTALKER) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2266,7 +2400,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-empty-rdns", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RDNS_MISSING]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RDNS_MISSING) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2283,7 +2417,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-graylist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_GRAYLISTED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_GRAYLISTED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2305,7 +2439,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-header-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_HEADER_BLACKLISTED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_HEADER_BLACKLISTED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2322,7 +2456,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-ip-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_BLACKLIST_IP]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_BLACKLIST_IP) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2339,7 +2473,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-ip-in-cc-rdns", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_IP_IN_NAME_CC]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_IP_IN_NAME_CC) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2356,7 +2490,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-ip-in-rdns-keyword-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_IP_IN_NAME]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_IP_IN_NAME) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2373,7 +2507,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-local-recipient", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RCPT_TO_LOCAL]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RCPT_TO_LOCAL) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2390,7 +2524,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-max-recipients", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RCPT_TO]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RCPT_TO) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2407,7 +2541,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-rdns-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_BLACKLIST_NAME]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_BLACKLIST_NAME) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2424,7 +2558,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-recipient-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RECIPIENT_BLACKLISTED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RECIPIENT_BLACKLISTED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2441,7 +2575,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-recipient-invalid", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_INVALID_RECIPIENT]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_INVALID_RECIPIENT) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2458,7 +2592,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-recipient-same-as-sender", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_IDENTICAL_FROM_TO]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_IDENTICAL_FROM_TO) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2475,7 +2609,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-recipient-unavailable", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_UNAVAILABLE_RECIPIENT]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_UNAVAILABLE_RECIPIENT) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2492,7 +2626,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-reject-all", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_UNCONDITIONAL]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_UNCONDITIONAL) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2509,7 +2643,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-relaying-denied", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RELAYING_DENIED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RELAYING_DENIED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2526,7 +2660,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-rhs-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RHSBL]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RHSBL) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2544,7 +2678,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-sender-authentication-mismatch", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SENDER_NOT_AUTH]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SENDER_NOT_AUTH) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2561,7 +2695,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-sender-blacklist", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SENDER_BLACKLISTED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SENDER_BLACKLISTED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2578,7 +2712,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-sender-no-mx", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SENDER_NO_MX]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SENDER_NO_MX) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2595,7 +2729,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-sender-not-local", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_SENDER_NOT_LOCAL]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_SENDER_NOT_LOCAL) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2612,7 +2746,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-smtp-auth-required", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_AUTH_REQUIRED]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_AUTH_REQUIRED) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2629,7 +2763,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-timeout", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_TIMEOUT]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_TIMEOUT) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2646,7 +2780,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-tls-failure", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[FAILURE_TLS]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, FAILURE_TLS) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2663,7 +2797,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-unresolvable-rdns", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_RDNS_RESOLVE]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_RDNS_RESOLVE) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2680,7 +2814,7 @@ int prepare_settings(int argc, char *arg
       { "rejection-text-zero-recipients", required_argument, NULL, -1 },
       { .string_value = NULL },
       { .string_value = NULL },
-      { .get_string = CONFIG_ACCESSOR_STRING(rejection_text[REJECTION_ZERO_RECIPIENTS]) },
+      { .get_string = CONFIG_ACCESSOR_STRING_ARRAY_MEMBER(rejection_text, REJECTION_ZERO_RECIPIENTS) },
       { .max_strlen = 100 },
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
@@ -2888,7 +3022,7 @@ int prepare_settings(int argc, char *arg
       FILTER_GRACE_NONE,
       &config_test_noop,
       NULL,
-      CONFIG_ACTION(if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_SET_MASK) == SMTP_AUTH_SET_VALUE_UNSET) && (current_settings->current_options->smtp_auth_command != NULL) && (current_settings->current_options->smtp_auth_command[0] != NULL)) { current_settings->current_options->smtp_auth_level = SMTP_AUTH_LEVEL_VALUE_ON_DEMAND | SMTP_AUTH_SET_VALUE_SET; if (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM; }),
+      CONFIG_ACTION(smtp_auth_verification, if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_SET_MASK) == SMTP_AUTH_SET_VALUE_UNSET) && (current_settings->current_options->smtp_auth_command != NULL) && (current_settings->current_options->smtp_auth_command[0] != NULL)) { current_settings->current_options->smtp_auth_level = SMTP_AUTH_LEVEL_VALUE_ON_DEMAND | SMTP_AUTH_SET_VALUE_SET; if (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM; }),
       "COMMAND",
       "Perform SMTP AUTH verification using COMMAND. spamdyke will only advertise cleartext authentication methods (unless qmail has been patched to advertise encrypted methods)."
       " If the authentication is valid, all filters will be bypassed. Most often, COMMAND is \"/bin/checkpassword /bin/true\". If \"smtp-auth-level\" is not given, \"smtp-auth-command\""
@@ -2912,7 +3046,7 @@ int prepare_settings(int argc, char *arg
       FILTER_GRACE_NONE,
       &config_test_smtpauth,
       NULL,
-      CONFIG_ACTION(if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_LEVEL_MASK) != SMTP_AUTH_LEVEL_VALUE_NONE) && (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM)) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM),
+      CONFIG_ACTION(smtp_auth_level, if (((current_settings->current_options->smtp_auth_level & SMTP_AUTH_LEVEL_MASK) != SMTP_AUTH_LEVEL_VALUE_NONE) && (current_settings->current_options->filter_grace < FILTER_GRACE_AFTER_FROM)) current_settings->current_options->filter_grace = FILTER_GRACE_AFTER_FROM),
       "LEVEL",
       "Support SMTP AUTH at LEVEL. LEVEL must be one of: none = do not allow or support SMTP AUTH, even if qmail supports it; observe"
       " = observe and honor authentication with qmail but qmail must offer it; ondemand = observe and honor authentication with qmail or offer and process"
@@ -3030,7 +3164,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_UNDECIDED,
       FILTER_GRACE_NONE,
       &config_test_tls_password,
-      CONFIG_SET_ACTION(current_settings->current_options->strlen_tls_privatekey_password = (current_settings->current_options->tls_privatekey_password != NULL) ? strlen(current_settings->current_options->tls_privatekey_password) : 0),
+      CONFIG_SET_ACTION(strlen_tls_privatekey_password, current_settings->current_options->strlen_tls_privatekey_password = (current_settings->current_options->tls_privatekey_password != NULL) ? strlen(current_settings->current_options->tls_privatekey_password) : 0),
       NULL,
       "PASSWORD",
       "Use PASSWORD to decrypt the SSL private key (from \"tls-certificate-file\" or \"tls-privatekey-file\"), if necessary. NOTE: this option reveals the password in the process list!"
@@ -3066,7 +3200,7 @@ int prepare_settings(int argc, char *arg
       FILTER_DECISION_ERROR,
       FILTER_GRACE_NONE,
       NULL,
-      CONFIG_SET_ACTION(usage(current_settings, USAGE_LEVEL_SHORT, NULL)),
+      CONFIG_SET_ACTION(usage_short, usage(current_settings, USAGE_LEVEL_SHORT, NULL)),
       NULL,
       NULL,
       "Displays the version number and copyright statement, then exits."
