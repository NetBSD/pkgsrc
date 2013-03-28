$NetBSD: patch-SRC_func.h,v 1.1 2013/03/28 21:37:24 joerg Exp $

--- SRC/func.h.orig	2013-03-28 16:11:01.000000000 +0000
+++ SRC/func.h
@@ -185,7 +185,7 @@ int dqs_return_consumable (dqs_job_type 
 #ifdef NO_PROTO
 int dqs_reset_consumable ();
 #else
-int dqs_reset_consumable (char *cname);
+void dqs_reset_consumable (char *cname);
 #endif
 #ifdef NO_PROTO
 int dqs_validate_resources ();
@@ -568,9 +568,9 @@ void dqs_parse_user_list ();
 void dqs_parse_user_list (dqs_list_type **head, char *user_str);
 #endif
 #ifdef NO_PROTO
-void * dqs_get_env_list ();
+void dqs_get_env_list ();
 #else
-void * dqs_get_env_list (dqs_list_type **head, char **envp);
+void dqs_get_env_list (dqs_list_type **head, char **envp);
 #endif
 #ifdef NO_PROTO
 void dqs_parse_destination_identifier_list ();
@@ -843,9 +843,9 @@ void dqs_show_states ();
 void dqs_show_states (u_long32 how, u_long32 states);
 #endif
 #ifdef NO_PROTO
-int dqs_show_queue_states ();
+void dqs_show_queue_states ();
 #else
-int dqs_show_queue_states (int state);
+void dqs_show_queue_states (int state);
 #endif
 #ifdef NO_PROTO
 u_long32 dqs_get_gmt ();
@@ -1103,9 +1103,9 @@ dqs_list_type * dqs_parse_qconf ();
 dqs_list_type * dqs_parse_qconf (dqs_list_type *argv_head, char **envp);
 #endif
 #ifdef NO_PROTO
-void * dqs_parse_destination_id_list ();
+void dqs_parse_destination_id_list ();
 #else
-void * dqs_parse_destination_id_list (dqs_list_type **head, char *cp, int opt);
+void dqs_parse_destination_id_list (dqs_list_type **head, char *cp, int opt);
 #endif
 #ifdef NO_PROTO
 void dqs_parse_name_list ();
@@ -1198,9 +1198,9 @@ void dqs_reap ();
 void dqs_reap ();
 #endif
 #ifdef NO_PROTO
-int dqs_reap_children ();
+void dqs_reap_children ();
 #else
-int dqs_reap_children ();
+void dqs_reap_children (void);
 #endif
 #ifdef NO_PROTO
 void dqs_c_qconf ();
@@ -1288,9 +1288,9 @@ int dqs_exec_mail ();
 int dqs_exec_mail (dqs_queue_type *qconf, dqs_job_type *job, int tag, string str);
 #endif
 #ifdef NO_PROTO
-int dqs_setenv ();
+void dqs_setenv ();
 #else
-int dqs_setenv (char *name, char *value, int overwrite);
+void dqs_setenv (char *name, char *value, int overwrite);
 #endif
 #ifdef NO_PROTO
 int dqs_reauth ();
@@ -1343,9 +1343,9 @@ void dqs_get_passwd_info ();
 void dqs_get_passwd_info (dqs_job_type *job);
 #endif
 #ifdef NO_PROTO
-int dqs_show_qstat_request ();
+void dqs_show_qstat_request ();
 #else
-int dqs_show_qstat_request (dqs_job_type *job);
+void dqs_show_qstat_request (dqs_job_type *job);
 #endif
 #ifdef NO_PROTO
 void dqs_job_exit ();
