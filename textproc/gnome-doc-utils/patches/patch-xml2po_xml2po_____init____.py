$NetBSD: patch-xml2po_xml2po_____init____.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/__init__.py.orig	2011-08-04 14:36:03.000000000 +0000
+++ xml2po/xml2po/__init__.py
@@ -86,14 +86,14 @@ class MessageOutput:
                 self.messages.append(t)
                 if spacepreserve:
                     self.nowrap[t] = True
-                if t in self.linenos.keys():
+                if t in list(self.linenos.keys()):
                     self.linenos[t].append((self.filename, tag, lineno))
                 else:
                     self.linenos[t] = [ (self.filename, tag, lineno) ]
                 if (not self.do_translations) and comment and not t in self.comments:
                     self.comments[t] = comment
             else:
-                if t in self.linenos.keys():
+                if t in list(self.linenos.keys()):
                     self.linenos[t].append((self.filename, tag, lineno))
                 else:
                     self.linenos[t] = [ (self.filename, tag, lineno) ]
@@ -200,7 +200,7 @@ class XMLDocument(object):
             tree = ctxt.doc()
             newnode = tree.getRootElement()
         except:
-            print >> sys.stderr, """Error while normalizing string as XML:\n"%s"\n""" % (text)
+            print("""Error while normalizing string as XML:\n"%s"\n""" % (text), file=sys.stderr)
             return text
 
         self.normalizeNode(newnode)
@@ -326,7 +326,7 @@ class XMLDocument(object):
                 pass
 
             content = '<%s>%s</%s>' % (starttag, text, endtag)
-            tmp = tmp + content.encode('utf-8')
+            tmp = tmp + content
 
             newnode = None
             try:
@@ -338,7 +338,7 @@ class XMLDocument(object):
                 pass
 
             if not newnode:
-                print >> sys.stderr, """Error while parsing translation as XML:\n"%s"\n""" % (text.encode('utf-8'))
+                print("""Error while parsing translation as XML:\n"%s"\n""" % (text.encode('utf-8')), file=sys.stderr)
                 return
 
             newelem = newnode.getRootElement()
@@ -352,9 +352,10 @@ class XMLDocument(object):
 
                 if node:
                     copy = newelem.copyNodeList()
-                    next = node.next
+                    #next = node.next
                     node.replaceNode(newelem.copyNodeList())
-                    node.next = next
+                    #print(type(next))
+                    #node.next = next
 
             else:
                 # In practice, this happens with tags such as "<para>    </para>" (only whitespace in between)
@@ -470,7 +471,7 @@ class XMLDocument(object):
 
         worth = self.worthOutputting(node)
         if not translation:
-            translation = outtxt.decode('utf-8')
+            translation = outtxt
             if worth and self.app.options.get('mark_untranslated'):
                 node.setLang('C')
 
@@ -577,8 +578,8 @@ class Main(object):
                 raise IOError("Unable to read file '%s'" % xmlfile)
             try:
                 doc = XMLDocument(xmlfile, self)
-            except Exception, e:
-                print >> sys.stderr, "Unable to parse XML file '%s': %s" % (xmlfile, str(e))
+            except Exception as e:
+                print("Unable to parse XML file '%s': %s" % (xmlfile, str(e)), file=sys.stderr)
                 sys.exit(1)
             self.current_mode.preProcessXml(doc.doc, self.msg)
             doc.generate_messages()
@@ -590,14 +591,14 @@ class Main(object):
             raise IOError("Unable to read file '%s'" % xmlfile)
         try:
             doc = XMLDocument(xmlfile, self)
-        except Exception, e:
-            print >> sys.stderr, str(e)
+        except Exception as e:
+            print(str(e), file=sys.stderr)
             sys.exit(1)
 
         try:
             mfile = open(mofile, "rb")
         except:
-            print >> sys.stderr, "Can't open MO file '%s'." % (mofile)
+            print("Can't open MO file '%s'." % (mofile), file=sys.stderr)
         self.gt = gettext.GNUTranslations(mfile)
         self.gt.add_fallback(NoneTranslations())
         # Has preProcessXml use cases for merge?
@@ -619,16 +620,16 @@ class Main(object):
             raise IOError("Unable to read file '%s'" % xmlfile)
         try:
             doc = XMLDocument(xmlfile, self)
-        except Exception, e:
-            print >> sys.stderr, str(e)
+        except Exception as e:
+            print(str(e), file=sys.stderr)
             sys.exit(1)
         doc.generate_messages()
 
         self.msg.translationsFollow()
         try:
             doc = XMLDocument(origxml, self)
-        except Exception, e:
-            print >> sys.stderr, str(e)
+        except Exception as e:
+            print(str(e), file=sys.stderr)
             sys.exit(1)
         doc.generate_messages()
         self.output_po()
@@ -663,7 +664,7 @@ class Main(object):
         if not text or text.strip() == '':
             return text
         if self.gt:
-            res = self.gt.ugettext(text.decode('utf-8'))
+            res = self.gt.gettext(text)
             return res
 
         return text
