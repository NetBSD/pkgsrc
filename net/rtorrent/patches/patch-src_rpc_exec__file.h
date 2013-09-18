$NetBSD: patch-src_rpc_exec__file.h,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/rpc/exec_file.h.orig	2012-01-19 10:18:01.000000000 +0000
+++ src/rpc/exec_file.h
@@ -43,13 +43,13 @@ namespace rpc {
 
 class ExecFile {
 public:
-  static const unsigned int max_args    = 128;
-  static const unsigned int buffer_size = 4096;
+  static const unsigned int max_args;
+  static const unsigned int buffer_size;
     
-  static const int flag_expand_tilde = 0x1;
-  static const int flag_throw        = 0x2;
-  static const int flag_capture      = 0x4;
-  static const int flag_background   = 0x8;
+  static const int flag_expand_tilde;
+  static const int flag_throw;
+  static const int flag_capture;
+  static const int flag_background;
 
   ExecFile() : m_logFd(-1) {}
 
