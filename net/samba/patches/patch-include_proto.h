$NetBSD: patch-include_proto.h,v 1.1 2026/07/21 21:17:39 rjs Exp $

Add prototype for lp_passwd_expand_gecos().

--- include/proto.h.orig	2026-07-21 17:23:51.351631122 +0000
+++ include/proto.h
@@ -1366,6 +1366,7 @@ char *lp_auto_services(void);
 char *lp_get_quota_command(void);
 char *lp_set_quota_command(void);
 char *lp_auto_services(void);
+bool lp_passwd_expand_gecos(void);
 char *lp_passwd_program(void);
 char *lp_passwd_chat(void);
 char *lp_passwordserver(void);
