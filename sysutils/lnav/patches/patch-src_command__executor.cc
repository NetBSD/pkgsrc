$NetBSD: patch-src_command__executor.cc,v 1.1 2023/05/24 22:42:53 he Exp $

Allow time_t to be long long, and adapt formats and casts accordingly.
Also, cast a size_t before printing; unknown size so difficult to match
format appropriately.

--- src/command_executor.cc.orig	2022-09-23 13:13:41.000000000 +0000
+++ src/command_executor.cc
@@ -478,10 +478,10 @@ execute_sql(exec_context& ec, const std:
                 snprintf(row_count_buf,
                          sizeof(row_count_buf),
                          ANSI_BOLD("%'d") " row%s matched in " ANSI_BOLD(
-                             "%ld.%03ld") " seconds",
+                             "%lld.%03ld") " seconds",
                          row_count,
                          row_count == 1 ? "" : "s",
-                         diff_tv.tv_sec,
+                         (long long)diff_tv.tv_sec,
                          std::max((long) diff_tv.tv_usec / 1000, 1L));
                 retval = row_count_buf;
                 if (dls.has_log_time_column()) {
@@ -624,7 +624,7 @@ execute_file(exec_context& ec, const std
 
     vars["#"] = env_arg_name;
     for (size_t lpc = 0; lpc < split_args.size(); lpc++) {
-        snprintf(env_arg_name, sizeof(env_arg_name), "%lu", lpc);
+        snprintf(env_arg_name, sizeof(env_arg_name), "%lu", (long unsigned int)lpc);
         vars[env_arg_name] = split_args[lpc];
     }
     for (size_t lpc = 1; lpc < split_args.size(); lpc++) {
