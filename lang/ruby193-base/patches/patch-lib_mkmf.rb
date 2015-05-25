$NetBSD: patch-lib_mkmf.rb,v 1.3.2.2 2015/05/25 01:04:35 hiramatsu Exp $

Avoid to generate empty command line on some platforms:

$(DLLIB): $(OBJS) Makefile
...
	$(Q) $(POSTLINK)

And POSTLINK is empty macro.  In such case, GNU make ignore empty command
line but BSD make tries to execute it and causes error.

--- lib/mkmf.rb.orig	2014-02-06 05:20:52.000000000 +0000
+++ lib/mkmf.rb
@@ -1722,6 +1722,7 @@ LDSHARED = #{CONFIG['LDSHARED']}
 LDSHAREDXX = #{config_string('LDSHAREDXX') || '$(LDSHARED)'}
 AR = #{CONFIG['AR']}
 EXEEXT = #{CONFIG['EXEEXT']}
+POSTLINK = #{CONFIG['POSTLINK']}
 
 RUBY_BASE_NAME = #{CONFIG['RUBY_BASE_NAME']}
 RUBY_INSTALL_NAME = #{CONFIG['RUBY_INSTALL_NAME']}
