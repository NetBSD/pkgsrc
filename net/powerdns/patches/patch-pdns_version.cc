$NetBSD: patch-pdns_version.cc,v 1.4 2025/12/27 19:04:17 wiz Exp $

Do not store configure args, as they contain workdir references.

--- pdns/version.cc.orig	2025-12-11 09:59:35.000000000 +0100
+++ pdns/version.cc
@@ -176,7 +176,7 @@
   ret << "Loaded modules: " << boost::join(modules, " ") << endl;
 #endif
 // NOLINTBEGIN(cppcoreguidelines-macro-usage)
-#ifdef PDNS_CONFIG_ARGS
+#if 0
 #define double_escape(s) #s
 #define escape_quotes(s) double_escape(s)
   // NOLINTEND(cppcoreguidelines-macro-usage)
