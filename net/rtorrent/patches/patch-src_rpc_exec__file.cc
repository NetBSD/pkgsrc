$NetBSD: patch-src_rpc_exec__file.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/rpc/exec_file.cc.orig	2013-05-03 23:11:48.000000000 +0000
+++ src/rpc/exec_file.cc
@@ -52,6 +52,14 @@ namespace rpc {
 
 // Close m_logFd.
 
+const unsigned int ExecFile::max_args    = 128;
+const unsigned int ExecFile::buffer_size = 4096;
+    
+const int ExecFile::flag_expand_tilde = 0x1;
+const int ExecFile::flag_throw        = 0x2;
+const int ExecFile::flag_capture      = 0x4;
+const int ExecFile::flag_background   = 0x8;
+
 int
 ExecFile::execute(const char* file, char* const* argv, int flags) {
   // Write the execued command and its parameters to the log fd.
