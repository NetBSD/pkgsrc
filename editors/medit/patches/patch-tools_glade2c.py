$NetBSD: patch-tools_glade2c.py,v 1.1 2021/04/11 00:58:16 tsutsui Exp $

- mechanical python3 support

--- tools/glade2c.py.orig	2012-12-16 23:55:32.000000000 +0000
+++ tools/glade2c.py
@@ -5,7 +5,7 @@ import sys
 import getopt
 import xml.dom
 import xml.dom.minidom as minidom
-import StringIO
+import io
 
 def name_is_nice(name):
     return name[-1:] not in "0123456789"
@@ -50,7 +50,7 @@ class GladeXml(object):
         walk_node(root, False, check_node)
 
     def format_buffer(self):
-        out = StringIO.StringIO()
+        out = io.StringIO()
         for l in self.buffer.splitlines():
             out.write('"')
             out.write(l.replace('\\', '\\\\').replace('"', '\\"'))
@@ -208,9 +208,9 @@ G_GNUC_UNUSED static %(XmlStruct)s *
 }
 """
 
-    buf = StringIO.StringIO()
+    buf = io.StringIO()
     if gxml.widgets:
-        print >> buf, ''
+        print('', file=buf)
         for w in gxml.widgets:
             name = w.name
             ct = params.id_map.get(name)
@@ -218,11 +218,11 @@ G_GNUC_UNUSED static %(XmlStruct)s *
                 class_name = w.class_name
             else:
                 class_name = ct[0]
-            print >> buf, '    %s *%s;' % (class_name, name)
+            print('    %s *%s;' % (class_name, name), file=buf)
     glade_xml_widgets_decl = buf.getvalue()
     buf.close()
 
-    buf = StringIO.StringIO()
+    buf = io.StringIO()
     for w in gxml.widgets:
         name = w.name
         ct = params.id_map.get(name)
@@ -230,20 +230,20 @@ G_GNUC_UNUSED static %(XmlStruct)s *
             class_name = w.class_name
         else:
             class_name = ct[0]
-        print >> buf, """\
+        print("""\
     xml->%(struct_mem)s = (%(class_name)s*) moo_glade_xml_get_widget (xml->xml, "%(glade_name)s");
-    g_return_val_if_fail (xml->%(struct_mem)s != NULL, FALSE);""" % { 'struct_mem': w.name, 'glade_name': w.real_name, 'class_name': class_name }
+    g_return_val_if_fail (xml->%(struct_mem)s != NULL, FALSE);""" % { 'struct_mem': w.name, 'glade_name': w.real_name, 'class_name': class_name }, file=buf)
     glade_xml_widgets_defs = buf.getvalue()
     buf.close()
 
-    buf = StringIO.StringIO()
+    buf = io.StringIO()
     for id in params.id_map:
         ct = params.id_map.get(id)
         if ct[1]:
             type_name = ct[1]
         else:
             type_name = 'g_type_from_name ("%s")' % (ct[0],)
-        print >> buf, '    moo_glade_xml_map_id (xml->xml, "%s", %s);' % (id, type_name)
+        print('    moo_glade_xml_map_id (xml->xml, "%s", %s);' % (id, type_name), file=buf)
     glade_xml_widgets_map = buf.getvalue()
     buf.close()
 
@@ -300,7 +300,7 @@ def convert_buffer(buf, params, output, 
 
         if output is None:
             output = sys.stdout
-        elif isinstance(output, str) or isinstance(output, unicode):
+        elif isinstance(output, str):
             output = open(output, 'w')
             close_output = True
 
@@ -317,7 +317,7 @@ def convert_file(filename, params, outpu
     return ret
 
 def usage():
-    print "Usage: %s [--map=id,ClassName,CLASS_TYPE...] [--output=outfile] FILE" % (sys.argv[0],)
+    print("Usage: %s [--map=id,ClassName,CLASS_TYPE...] [--output=outfile] FILE" % (sys.argv[0],))
 
 def main(args):
     params = ConvertParams()
@@ -325,8 +325,8 @@ def main(args):
     try:
         opts, files = getopt.getopt(args[1:], "hm:o:s:S:r:",
                                     ["help", "map=", "output=", "struct-name=", "StructName=", "root="])
-    except getopt.GetoptError, err:
-        print str(err)
+    except getopt.GetoptError as err:
+        print(str(err))
         usage()
         return 2
 
