$NetBSD: patch-src_api_ruby_rubyincludes1.h,v 1.1 2017/06/12 17:06:18 taca Exp $

Use better cast for Ruby 2.1 and later.

--- src/api/ruby/rubyincludes1.h.orig	2016-12-20 08:40:41.000000000 +0000
+++ src/api/ruby/rubyincludes1.h
@@ -1 +1 @@
-#define CAST VALUE(*)()
+#define CAST VALUE(*)(ANYARGS)
