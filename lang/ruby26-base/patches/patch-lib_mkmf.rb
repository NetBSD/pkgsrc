$NetBSD: patch-lib_mkmf.rb,v 1.1 2019/02/03 13:41:33 taca Exp $

Avoid to generate empty command line on some platforms:

$(DLLIB): $(OBJS) Makefile
...
	$(Q) $(POSTLINK)

And POSTLINK is empty macro.  In such case, GNU make ignore empty command
line but BSD make tries to execute it and causes error.

--- lib/mkmf.rb.orig	2017-03-11 18:46:17.000000000 +0000
+++ lib/mkmf.rb
@@ -1988,6 +1988,7 @@ LDSHARED = #{CONFIG['LDSHARED']}
 LDSHAREDXX = #{config_string('LDSHAREDXX') || '$(LDSHARED)'}
 AR = #{CONFIG['AR']}
 EXEEXT = #{CONFIG['EXEEXT']}
+POSTLINK = #{CONFIG['POSTLINK']}
 
 }
     CONFIG.each do |key, val|
