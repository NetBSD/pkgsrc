$NetBSD: patch-scripts_mk__genfile__common.py,v 1.1 2020/05/31 20:49:34 joerg Exp $

--- scripts/mk_genfile_common.py.orig	2018-11-19 20:21:17.000000000 +0000
+++ scripts/mk_genfile_common.py
@@ -622,7 +622,8 @@ def mk_gparams_register_modules_internal
     reg_mod_descr_pat = re.compile('[ \t]*REG_MODULE_DESCRIPTION\(\'([^\']*)\', *\'([^\']*)\'\)')
     for h_file in sorted_headers_by_component(h_files_full_path):
         added_include = False
-        with open(h_file, 'r') as fin:
+        py3args = { 'encoding': 'UTF-8' } if sys.version_info.major >= 3 else {}
+        with open(h_file, 'r', **py3args) as fin:
             for line in fin:
                 m = reg_pat.match(line)
                 if m:
@@ -696,7 +697,8 @@ def mk_install_tactic_cpp_internal(h_fil
     for h_file in sorted_headers_by_component(h_files_full_path):
         added_include = False
         try:
-            with open(h_file, 'r') as fin:
+            py3args = { 'encoding': 'UTF-8' } if sys.version_info.major >= 3 else {}
+            with open(h_file, 'r', **py3args) as fin:
                 for line in fin:
                     if tactic_pat.match(line):
                         if not added_include:
@@ -764,7 +766,8 @@ def mk_mem_initializer_cpp_internal(h_fi
     finalizer_pat        = re.compile('[ \t]*ADD_FINALIZER\(\'([^\']*)\'\)')
     for h_file in sorted_headers_by_component(h_files_full_path):
         added_include = False
-        with open(h_file, 'r') as fin:
+        py3args = { 'encoding': 'UTF-8' } if sys.version_info.major >= 3 else {}
+        with open(h_file, 'r', **py3args) as fin:
             for line in fin:
                 m = initializer_pat.match(line)
                 if m:
@@ -806,7 +809,8 @@ def mk_pat_db_internal(inputFilePath, ou
     """
         Generate ``g_pattern_database[]`` declaration header file.
     """
-    with open(inputFilePath, 'r') as fin:
+    py3args = { 'encoding': 'UTF-8' } if sys.version_info.major >= 3 else {}
+    with open(inputFilePath, 'r', **py3args) as fin:
         with open(outputFilePath, 'w') as fout:
             fout.write('static char const g_pattern_database[] =\n')
             for line in fin:
