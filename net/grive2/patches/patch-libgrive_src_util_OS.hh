$NetBSD: patch-libgrive_src_util_OS.hh,v 1.2 2021/04/15 10:43:01 wiz Exp $

off64_t is not universally available.
https://github.com/vitalif/grive2/pull/342

--- libgrive/src/util/OS.hh.orig	2019-11-12 22:05:31.000000000 +0000
+++ libgrive/src/util/OS.hh
@@ -31,6 +31,10 @@ class Path ;
 
 enum FileType { FT_FILE = 1, FT_DIR = 2, FT_UNKNOWN = 3 } ;
 
+#ifndef off64_t
+#define off64_t off_t
+#endif
+
 namespace os
 {
 	struct Error : virtual Exception {} ;
