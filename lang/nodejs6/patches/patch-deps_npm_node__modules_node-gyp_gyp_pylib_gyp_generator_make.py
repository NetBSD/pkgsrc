$NetBSD: patch-deps_npm_node__modules_node-gyp_gyp_pylib_gyp_generator_make.py,v 1.1 2016/10/25 19:54:00 fhajny Exp $

Ensure we use the system libtool on OSX.

--- deps/npm/node_modules/node-gyp/gyp/pylib/gyp/generator/make.py.orig	2013-06-13 17:35:30.000000000 +0000
+++ deps/npm/node_modules/node-gyp/gyp/pylib/gyp/generator/make.py
@@ -161,7 +161,7 @@ cmd_solink_module = $(LINK.$(TOOLSET)) -
 
 LINK_COMMANDS_MAC = """\
 quiet_cmd_alink = LIBTOOL-STATIC $@
-cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
+cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool /usr/bin/libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
 
 quiet_cmd_link = LINK($(TOOLSET)) $@
 cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o "$@" $(LD_INPUTS) $(LIBS)
