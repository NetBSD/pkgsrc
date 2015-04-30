$NetBSD: patch-lib_mkmf.rb,v 1.1 2015/04/30 03:26:37 taca Exp $

Avoid to generate empty command line on some platforms:

$(DLLIB): $(OBJS) Makefile
...
	$(Q) $(POSTLINK)

And POSTLINK is empty macro.  In such case, GNU make ignore empty command
line but BSD make tries to execute it and causes error.

--- lib/mkmf.rb.orig	2015-02-25 05:26:38.000000000 +0000
+++ lib/mkmf.rb
@@ -1862,6 +1862,7 @@ LDSHARED = #{CONFIG['LDSHARED']}
 LDSHAREDXX = #{config_string('LDSHAREDXX') || '$(LDSHARED)'}
 AR = #{CONFIG['AR']}
 EXEEXT = #{CONFIG['EXEEXT']}
+POSTLINK = #{CONFIG['POSTLINK']}
 
 }
     CONFIG.each do |key, val|
