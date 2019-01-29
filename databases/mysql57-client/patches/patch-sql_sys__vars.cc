$NetBSD: patch-sql_sys__vars.cc,v 1.1.2.2 2019/01/29 13:01:46 bsiegert Exp $

Backport of https://github.com/mysql/mysql-server/commit/98ed3d8bc8ad724686d26c7bf98dced3bd1777be
Avoid disclosure of files from a client to a malicious server, described here:
https://gwillem.gitlab.io/2019/01/17/adminer-4.6.2-file-disclosure-vulnerability/

--- sql/sys_vars.cc.orig	2018-10-04 05:48:22.000000000 +0000
+++ sql/sys_vars.cc
@@ -1809,7 +1809,7 @@ static Sys_var_charptr Sys_language(
 
 static Sys_var_mybool Sys_local_infile(
        "local_infile", "Enable LOAD DATA LOCAL INFILE",
-       GLOBAL_VAR(opt_local_infile), CMD_LINE(OPT_ARG), DEFAULT(TRUE));
+       GLOBAL_VAR(opt_local_infile), CMD_LINE(OPT_ARG), DEFAULT(FALSE));
 
 static Sys_var_ulong Sys_lock_wait_timeout(
        "lock_wait_timeout",
