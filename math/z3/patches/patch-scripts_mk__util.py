$NetBSD: patch-scripts_mk__util.py,v 1.6 2020/05/31 20:49:34 joerg Exp $

--- scripts/mk_util.py.orig	2018-11-19 20:21:17.000000000 +0000
+++ scripts/mk_util.py
@@ -803,7 +803,8 @@ def extract_c_includes(fname):
     # We should generate and error for any occurrence of #include that does not match the previous pattern.
     non_std_inc_pat = re.compile(".*#include.*")
 
-    f = open(fname, 'r')
+    py3args = { 'encoding': 'UTF-8' } if sys.version_info.major >= 3 else {}
+    f = open(fname, 'r', **py3args)
     linenum = 1
     for line in f:
         m1 = std_inc_pat.match(line)
@@ -2001,7 +2002,7 @@ class JavaDLLComponent(Component):
                 out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) %s$(OBJ_EXT) libz3$(LIB_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))
             else:
-                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
+                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) $(JAVA_LINK_EXTRA_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))
             out.write('%s.jar: libz3java$(SO_EXT) ' % self.package_name)
             deps = ''
@@ -2694,7 +2695,8 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = LDFLAGS
+        JAVALIBEXTRAFLAGS = LDFLAGS
         EXE_EXT = ''
         LIB_EXT = '.a'
         if GPROF:
@@ -2822,6 +2824,7 @@ def mk_config():
         config.write('SLINK_FLAGS=%s\n' % SLIBFLAGS)
         config.write('SLINK_EXTRA_FLAGS=%s\n' % SLIBEXTRAFLAGS)
         config.write('SLINK_OUT_FLAG=-o \n')
+        config.write('JAVA_LINK_EXTRA_FLAGS=%s\n' % JAVALIBEXTRAFLAGS)
         config.write('OS_DEFINES=%s\n' % OS_DEFINES)
         if is_verbose():
             print('Host platform:  %s' % sysname)
