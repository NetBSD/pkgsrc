$NetBSD: patch-rtrmgr_cli.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rtrmgr/cli.cc.orig	2012-07-03 16:29:27.000000000 +0000
+++ rtrmgr/cli.cc
@@ -741,7 +741,7 @@ RouterCLI::op_mode_help(const vector<str
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
@@ -1062,7 +1062,7 @@ RouterCLI::configure_mode_help(const vec
     path = token_vector2line(command_global_name);
     XLOG_ASSERT(path.substr(0, 4) == "help");
     if (path.size() == 4) {
-	trimmed_path == "";
+	trimmed_path = "";
     } else {
 	XLOG_ASSERT(path.substr(0, 5) == "help ");
 	trimmed_path = path.substr(5, path.size() - 5);
