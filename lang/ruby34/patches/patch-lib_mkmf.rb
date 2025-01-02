$NetBSD: patch-lib_mkmf.rb,v 1.1 2025/01/02 06:51:05 taca Exp $

* Avoid to generate empty command line on some platforms.

--- lib/mkmf.rb.orig	2024-12-12 01:10:13.000000000 +0000
+++ lib/mkmf.rb
@@ -2286,6 +2286,7 @@ RULES
       line.gsub!(/\.o\b/, ".#{$OBJEXT}")
       line.gsub!(/\{\$\(VPATH\)\}/, "") unless $nmake
       line.gsub!(/\$\((?:hdr|top)dir\)\/config.h/, $config_h)
+      line.gsub!(%r"\$\(hdrdir\)/(?!ruby(?![^:;/\s]))(?=[-\w]+\.h)", '\&ruby/')
       if $nmake && /\A\s*\$\(RM|COPY\)/ =~ line
         line.gsub!(%r"[-\w\./]{2,}"){$&.tr("/", "\\")}
         line.gsub!(/(\$\((?!RM|COPY)[^:)]+)(?=\))/, '\1:/=\\')
