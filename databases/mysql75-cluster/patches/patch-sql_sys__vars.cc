$NetBSD: patch-sql_sys__vars.cc,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- sql/sys_vars.cc.orig	2021-09-14 09:08:08.000000000 +0000
+++ sql/sys_vars.cc
@@ -1822,7 +1822,7 @@ static Sys_var_charptr Sys_language(
 
 static Sys_var_mybool Sys_local_infile(
        "local_infile", "Enable LOAD DATA LOCAL INFILE",
-       GLOBAL_VAR(opt_local_infile), CMD_LINE(OPT_ARG), DEFAULT(TRUE));
+       GLOBAL_VAR(opt_local_infile), CMD_LINE(OPT_ARG), DEFAULT(FALSE));
 
 static Sys_var_ulong Sys_lock_wait_timeout(
        "lock_wait_timeout",
