$NetBSD: patch-tools_gyp_pylib_gyp_generator_make.py,v 1.3 2013/12/12 11:52:37 jperkin Exp $

Add support for NetBSD and DragonFly.
Ensure we use the system libtool on OSX.

--- tools/gyp/pylib/gyp/generator/make.py.orig	2013-12-12 05:20:06.000000000 +0000
+++ tools/gyp/pylib/gyp/generator/make.py
@@ -174,7 +174,7 @@ cmd_solink_module = $(LINK.$(TOOLSET)) -
 
 LINK_COMMANDS_MAC = """\
 quiet_cmd_alink = LIBTOOL-STATIC $@
-cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
+cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool /usr/bin/libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
 
 quiet_cmd_link = LINK($(TOOLSET)) $@
 cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o "$@" $(LD_INPUTS) $(LIBS)
@@ -2012,7 +2012,7 @@ def GenerateOutput(target_list, target_d
         'flock': './gyp-flock-tool flock',
         'flock_index': 2,
     })
-  elif flavor == 'freebsd':
+  elif flavor == 'freebsd' or flavor == 'dragonflybsd' or flavor == 'netbsd':
     # Note: OpenBSD has sysutils/flock. lockf seems to be FreeBSD specific.
     header_params.update({
         'flock': 'lockf',
