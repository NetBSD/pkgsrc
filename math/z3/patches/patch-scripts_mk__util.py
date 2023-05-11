$NetBSD: patch-scripts_mk__util.py,v 1.8 2023/05/11 06:43:43 adam Exp $

Try to at least be slightly more portable.

--- scripts/mk_util.py.orig	2023-01-18 03:10:26.000000000 +0000
+++ scripts/mk_util.py
@@ -1858,7 +1858,7 @@ class JavaDLLComponent(Component):
                 out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) -arch arm64 %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))                
             else:
-                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
+                out.write('\t$(SLINK) $(SLINK_OUT_FLAG)libz3java$(SO_EXT) $(SLINK_FLAGS) $(JAVA_LINK_EXTRA_FLAGS) %s$(OBJ_EXT) libz3$(SO_EXT)\n' %
                           os.path.join('api', 'java', 'Native'))
             out.write('%s.jar: libz3java$(SO_EXT) ' % self.package_name)
             deps = ''
@@ -2577,7 +2577,8 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = LDFLAGS
+        JAVALIBEXTRAFLAGS = LDFLAGS
 #       SLIBEXTRAFLAGS = '%s -Wl,-soname,libz3.so.0' % LDFLAGS
         EXE_EXT = ''
         LIB_EXT = '.a'
@@ -2647,7 +2648,8 @@ def mk_config():
             EXE_EXT        = '.exe'
             LIB_EXT        = '.lib'
         else:
-            raise MKException('Unsupported platform: %s' % sysname)
+            SO_EXT         = '.so'
+            SLIBFLAGS      = '-shared'
         if is64():
             if not sysname.startswith('CYGWIN') and not sysname.startswith('MSYS') and not sysname.startswith('MINGW'):
                 CXXFLAGS     = '%s -fPIC' % CXXFLAGS
@@ -2696,6 +2698,7 @@ def mk_config():
         config.write('SLINK_FLAGS=%s\n' % SLIBFLAGS)
         config.write('SLINK_EXTRA_FLAGS=-lpthread %s\n' % SLIBEXTRAFLAGS)
         config.write('SLINK_OUT_FLAG=-o \n')
+        config.write('JAVA_LINK_EXTRA_FLAGS=%s\n' % JAVALIBEXTRAFLAGS)
         config.write('OS_DEFINES=%s\n' % OS_DEFINES)
         if is_verbose():
             print('Host platform:  %s' % sysname)
