$NetBSD: patch-src_utils.cc,v 1.1 2022/04/25 14:34:06 tnn Exp $

provide fallback declaration for ACCESSPERMS

--- src/utils.cc.orig	2021-10-07 19:33:41.000000000 +0000
+++ src/utils.cc
@@ -401,6 +401,9 @@ void check_or_mk_dir(const string& path)
             cerr << "Error: '" << *path_p << "' is not a directory.\n";
             throw exception();
         }
+#ifndef ACCESSPERMS
+#define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)
+#endif
     } else if (mkdir(path_p->c_str(), ACCESSPERMS) != 0) {
         //
         // Failed to create the directory.
