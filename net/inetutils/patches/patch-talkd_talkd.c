$NetBSD: patch-talkd_talkd.c,v 1.1 2026/08/15 06:46:44 wiz Exp $

Fix CVE-2026-19720.
https://codeberg.org/inetutils/inetutils/commit/81987d968ab831c08bd7e42a46f4a4823729cf1e

--- talkd/talkd.c.orig	2026-04-29 07:53:25.000000000 +0000
+++ talkd/talkd.c
@@ -41,6 +41,7 @@ char *hostname;
 
 char *acl_file;
 char *hostname;
+idx_t hostname_len;
 
 const char args_doc[] = "";
 const char doc[] = "Talk daemon, using service `ntalk'.";
@@ -131,6 +132,7 @@ talkd_init (void)
       syslog (LOG_ERR, "Cannot determine my hostname: %m");
       exit (EXIT_FAILURE);
     }
+  hostname_len = strlen (hostname);
 }
 
 time_t last_msg_time;
