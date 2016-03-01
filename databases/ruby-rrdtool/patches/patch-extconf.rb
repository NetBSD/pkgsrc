$NetBSD: patch-extconf.rb,v 1.1 2016/03/01 17:13:59 adam Exp $

Use correct rpath.

--- extconf.rb.orig	2016-03-01 17:03:18.648406906 +0000
+++ extconf.rb
@@ -13,6 +13,6 @@ elsif /aix/ =~ RUBY_PLATFORM
    $LDFLAGS += ' -blibpath:$(EPREFIX)/lib'
 end
 
-dir_config("rrd",['$(ABS_TOP_BUILDDIR)/src', '$(ABS_TOP_SRCDIR)/src'],'$(ABS_TOP_BUILDDIR)/src/.libs')
+dir_config("rrd",['$(ABS_TOP_BUILDDIR)/src', '$(ABS_TOP_SRCDIR)/src'],'$(EPREFIX)/lib')
 have_library("rrd", "rrd_create")
 create_makefile("RRD")
