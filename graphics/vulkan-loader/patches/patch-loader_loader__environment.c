$NetBSD: patch-loader_loader__environment.c,v 1.1 2026/06/22 08:12:21 kikadf Exp $

* Fix ctype usage

--- loader/loader_environment.c.orig	2026-05-01 06:43:23.000000000 +0200
+++ loader/loader_environment.c
@@ -49,7 +49,7 @@ char *loader_getenv(const char *name, co
 }
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
@@ -264,7 +264,7 @@ VkResult parse_generic_filter_environmen
     }
 
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
@@ -324,7 +324,7 @@ VkResult parse_layers_disable_filter_env
     }
 
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
@@ -396,7 +396,7 @@ bool check_name_matches_filter_environme
     const size_t name_len = strlen(name);
     char lower_name[VK_MAX_EXTENSION_NAME_SIZE];
     for (uint32_t iii = 0; iii < name_len; ++iii) {
-        lower_name[iii] = (char)tolower(name[iii]);
+        lower_name[iii] = (char)tolower((unsigned char)name[iii]);
     }
     lower_name[name_len] = '\0';
     for (uint32_t filt = 0; filt < filter_struct->count; ++filt) {
@@ -578,7 +578,7 @@ void parse_id_filter_environment_var(con
     // Allocate a separate string since scan_for_next_comma modifies the original string
     parsing_string = loader_stack_alloc(env_var_len + 1);
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
