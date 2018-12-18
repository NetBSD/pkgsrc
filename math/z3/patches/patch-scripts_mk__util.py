$NetBSD: patch-scripts_mk__util.py,v 1.5 2018/12/18 06:46:39 kamil Exp $

--- scripts/mk_util.py.orig	2018-12-15 09:28:53.381588998 +0000
+++ scripts/mk_util.py
@@ -2001,7 +2001,7 @@ class JavaDLLComponent(Component):
                 out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) %s$(OBJ_EXT) libz3$(LIB_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))
             else:
-                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
+                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) $(JAVA_LINK_EXTRA_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))
             out.write('%s.jar: libz3java$(SO_EXT) ' % self.package_name)
             deps = ''
@@ -2694,7 +2694,8 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = LDFLAGS
+        JAVALIBEXTRAFLAGS = LDFLAGS
         EXE_EXT = ''
         LIB_EXT = '.a'
         if GPROF:
@@ -2822,6 +2823,7 @@ def mk_config():
         config.write('SLINK_FLAGS=%s\n' % SLIBFLAGS)
         config.write('SLINK_EXTRA_FLAGS=%s\n' % SLIBEXTRAFLAGS)
         config.write('SLINK_OUT_FLAG=-o \n')
+        config.write('JAVA_LINK_EXTRA_FLAGS=%s\n' % JAVALIBEXTRAFLAGS)
         config.write('OS_DEFINES=%s\n' % OS_DEFINES)
         if is_verbose():
             print('Host platform:  %s' % sysname)
