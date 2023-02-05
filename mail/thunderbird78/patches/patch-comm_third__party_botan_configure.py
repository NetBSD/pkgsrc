$NetBSD: patch-comm_third__party_botan_configure.py,v 1.1 2023/02/05 08:32:24 he Exp $

* pkgsrc uses clang as c++.

--- comm/third_party/botan/configure.py.orig	2020-08-28 21:34:19.000000000 +0000
+++ comm/third_party/botan/configure.py
@@ -2940,7 +2940,7 @@ def set_defaults_for_unset_options(optio
             return 'clang'
         if cc_bin.find('-g++') != -1 or cc_bin.find('g++') != -1:
             return 'gcc'
-        return None
+        return 'clang'
 
     if options.compiler is None and options.compiler_binary is not None:
         options.compiler = deduce_compiler_type_from_cc_bin(options.compiler_binary)
