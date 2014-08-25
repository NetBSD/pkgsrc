$NetBSD: patch-pylib_gyp_generator_make.py,v 1.4 2014/08/25 13:20:12 fhajny Exp $

Force platform libtool na Darwin, see
https://code.google.com/p/gyp/issues/detail?id=354&q=libtool

Also, don't try to use thin archives on NetBSD, they appear not to work
("ar t <archive>" says "Malformed archive").

--- pylib/gyp/generator/make.py.orig	2014-07-14 14:19:49.000000000 +0000
+++ pylib/gyp/generator/make.py
@@ -167,9 +167,83 @@ quiet_cmd_solink_module = SOLINK_MODULE(
 cmd_solink_module = $(LINK.$(TOOLSET)) -shared $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -Wl,-soname=$(@F) -o $@ -Wl,--start-group $(filter-out FORCE_DO_CMD, $^) -Wl,--end-group $(LIBS)
 """
 
+LINK_COMMANDS_NETBSD = """\
+quiet_cmd_alink = AR($(TOOLSET)) $@
+cmd_alink = rm -f $@ && $(AR.$(TOOLSET)) crs $@ $(filter %.o,$^)
+
+quiet_cmd_alink_thin = AR($(TOOLSET)) $@
+# Thin archives do not appear to work with the NetBSD-supplied version of GNU ar, so work around that
+cmd_alink_thin = rm -f $@ && $(AR.$(TOOLSET)) crs $@ $(filter %.o,$^)
+
+# Due to circular dependencies between libraries :(, we wrap the
+# special "figure out circular dependencies" flags around the entire
+# input list during linking.
+quiet_cmd_link = LINK($(TOOLSET)) $@
+cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o $@ -Wl,--start-group $(LD_INPUTS) -Wl,--end-group $(LIBS)
+
+# We support two kinds of shared objects (.so):
+# 1) shared_library, which is just bundling together many dependent libraries
+# into a link line.
+# 2) loadable_module, which is generating a module intended for dlopen().
+#
+# They differ only slightly:
+# In the former case, we want to package all dependent code into the .so.
+# In the latter case, we want to package just the API exposed by the
+# outermost module.
+# This means shared_library uses --whole-archive, while loadable_module doesn't.
+# (Note that --whole-archive is incompatible with the --start-group used in
+# normal linking.)
+
+# Other shared-object link notes:
+# - Set SONAME to the library filename so our binaries don't reference
+# the local, absolute paths used on the link command-line.
+quiet_cmd_solink = SOLINK($(TOOLSET)) $@
+cmd_solink = $(LINK.$(TOOLSET)) -shared $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -Wl,-soname=$(@F) -o $@ -Wl,--whole-archive $(LD_INPUTS) -Wl,--no-whole-archive $(LIBS)
+
+quiet_cmd_solink_module = SOLINK_MODULE($(TOOLSET)) $@
+cmd_solink_module = $(LINK.$(TOOLSET)) -shared $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -Wl,-soname=$(@F) -o $@ -Wl,--start-group $(filter-out FORCE_DO_CMD, $^) -Wl,--end-group $(LIBS)
+"""
+
+LINK_COMMANDS_SOLARIS = """\
+quiet_cmd_alink = AR($(TOOLSET)) $@
+cmd_alink = rm -f $@ && $(AR.$(TOOLSET)) crs $@ $(filter %.o,$^)
+
+quiet_cmd_alink_thin = AR($(TOOLSET)) $@
+# Thin archives do not appear to work with the NetBSD-supplied version of GNU ar, so work around that
+cmd_alink_thin = rm -f $@ && $(AR.$(TOOLSET)) crs $@ $(filter %.o,$^)
+
+# Due to circular dependencies between libraries :(, we wrap the
+# special "figure out circular dependencies" flags around the entire
+# input list during linking.
+quiet_cmd_link = LINK($(TOOLSET)) $@
+cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o $@ -Wl,--start-group $(LD_INPUTS) -Wl,--end-group $(LIBS)
+
+# We support two kinds of shared objects (.so):
+# 1) shared_library, which is just bundling together many dependent libraries
+# into a link line.
+# 2) loadable_module, which is generating a module intended for dlopen().
+#
+# They differ only slightly:
+# In the former case, we want to package all dependent code into the .so.
+# In the latter case, we want to package just the API exposed by the
+# outermost module.
+# This means shared_library uses --whole-archive, while loadable_module doesn't.
+# (Note that --whole-archive is incompatible with the --start-group used in
+# normal linking.)
+
+# Other shared-object link notes:
+# - Set SONAME to the library filename so our binaries don't reference
+# the local, absolute paths used on the link command-line.
+quiet_cmd_solink = SOLINK($(TOOLSET)) $@
+cmd_solink = $(LINK.$(TOOLSET)) -shared $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -Wl,-soname=$(@F) -o $@ -Wl,--whole-archive $(LD_INPUTS) -Wl,--no-whole-archive $(LIBS)
+
+quiet_cmd_solink_module = SOLINK_MODULE($(TOOLSET)) $@
+cmd_solink_module = $(LINK.$(TOOLSET)) -shared $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -Wl,-soname=$(@F) -o $@ -Wl,--start-group $(filter-out FORCE_DO_CMD, $^) -Wl,--end-group $(LIBS)
+"""
+
 LINK_COMMANDS_MAC = """\
 quiet_cmd_alink = LIBTOOL-STATIC $@
-cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
+cmd_alink = rm -f $@ && ./gyp-mac-tool filter-libtool /usr/bin/libtool $(GYP_LIBTOOLFLAGS) -static -o $@ $(filter %.o,$^)
 
 quiet_cmd_link = LINK($(TOOLSET)) $@
 cmd_link = $(LINK.$(TOOLSET)) $(GYP_LDFLAGS) $(LDFLAGS.$(TOOLSET)) -o "$@" $(LD_INPUTS) $(LIBS)
@@ -350,7 +424,7 @@ sed -e "s|^$(notdir $@)|$@|" $(depfile).
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 's| |${NL}|g' $(depfile).raw |\
   grep -v '^$$'                             |\
   sed -e 1d -e 's|$$|:|'                     \
     >> $(depfile)
@@ -2044,6 +2118,7 @@ def GenerateOutput(target_list, target_d
     header_params.update({
         'flock': './gyp-flock-tool flock',
         'flock_index': 2,
+        'link_commands': LINK_COMMANDS_SOLARIS,
     })
   elif flavor == 'freebsd':
     # Note: OpenBSD has sysutils/flock. lockf seems to be FreeBSD specific.
@@ -2056,6 +2131,11 @@ def GenerateOutput(target_list, target_d
         'flock': './gyp-flock-tool flock',
         'flock_index': 2,
     })
+  elif flavor == 'netbsd':
+    header_params.update({
+        'link_commands': LINK_COMMANDS_NETBSD,
+    })
+        
 
   header_params.update({
     'CC.target':   GetEnvironFallback(('CC_target', 'CC'), '$(CC)'),
