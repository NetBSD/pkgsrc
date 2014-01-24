$NetBSD: patch-pylib_gyp_generator_make.py,v 1.2 2014/01/24 13:28:30 fhajny Exp $

Force platform libtool na Darwin, see
https://code.google.com/p/gyp/issues/detail?id=354&q=libtool
--- pylib/gyp/generator/make.py.orig	2013-09-06 23:07:36.000000000 +0000
+++ pylib/gyp/generator/make.py
@@ -161,7 +161,7 @@ cmd_solink_module = $(LINK.$(TOOLSET)) -
 
 LINK_COMMANDS_MAC = """\
 quiet_cmd_alink = LIBTOOL-STATIC $@
-cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
+cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool /usr/bin/libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
 
 quiet_cmd_link = LINK($(TOOLSET)) $@
 cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o "$@" $(LD_INPUTS) $(LIBS)
@@ -324,7 +324,7 @@ sed -e "s|^$(notdir $@)|$@|" $(depfile).
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 's| |${NL}|g' $(depfile).raw |\
   grep -v '^$$'                             |\
   sed -e 1d -e 's|$$|:|'                     \
     >> $(depfile)
