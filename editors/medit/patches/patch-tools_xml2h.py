$NetBSD: patch-tools_xml2h.py,v 1.1 2021/04/11 00:58:16 tsutsui Exp $

- mechanical python3 support

--- tools/xml2h.py.orig	2012-12-16 23:55:32.000000000 +0000
+++ tools/xml2h.py
@@ -11,13 +11,13 @@ tmp_output = output + '.tmp'
 varname = sys.argv[3]
 
 outfile = open(tmp_output, 'w')
-print >> outfile, '/* -*- C -*- */'
-print >> outfile, 'static const char %s [] = ""' % (varname,)
+print('/* -*- C -*- */', file=outfile)
+print('static const char %s [] = ""' % (varname,), file=outfile)
 for line in open(input):
     if line.endswith('\n'):
         line = line[:-1]
-    print >> outfile, '"' + line.replace('"', '\\"') + '\\n"'
-print >> outfile, ';'
+    print('"' + line.replace('"', '\\"') + '\\n"', file=outfile)
+print(';', file=outfile)
 
 outfile.close()
 
