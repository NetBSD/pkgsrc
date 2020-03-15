$NetBSD: patch-lib_mkmf.rb,v 1.1 2020/03/15 15:26:22 taca Exp $

* Avoid to generate empty command line on some platforms.
* Make compatible processing dependency output as Ruby 2.6.

$(DLLIB): $(OBJS) Makefile
...
	$(Q) $(POSTLINK)

And POSTLINK is empty macro.  In such case, GNU make ignore empty command
line but BSD make tries to execute it and causes error.

--- lib/mkmf.rb.orig	2019-12-25 09:50:58.000000000 +0000
+++ lib/mkmf.rb
@@ -2023,6 +2023,7 @@ LDSHARED = #{CONFIG['LDSHARED']}
 LDSHAREDXX = #{config_string('LDSHAREDXX') || '$(LDSHARED)'}
 AR = #{CONFIG['AR']}
 EXEEXT = #{CONFIG['EXEEXT']}
+POSTLINK = #{CONFIG['POSTLINK']}
 
 }
     CONFIG.each do |key, val|
@@ -2134,6 +2135,7 @@ RULES
       line.gsub!(/\.o\b/, ".#{$OBJEXT}")
       line.gsub!(/\{\$\(VPATH\)\}/, "") unless $nmake
       line.gsub!(/\$\((?:hdr|top)dir\)\/config.h/, $config_h)
+      line.gsub!(%r"\$\(hdrdir\)/(?!ruby(?![^:;/\s]))(?=[-\w]+\.h)", '\&ruby/')
       if $nmake && /\A\s*\$\(RM|COPY\)/ =~ line
         line.gsub!(%r"[-\w\./]{2,}"){$&.tr("/", "\\")}
         line.gsub!(/(\$\((?!RM|COPY)[^:)]+)(?=\))/, '\1:/=\\')
