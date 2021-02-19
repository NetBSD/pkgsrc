$NetBSD: patch-xml2po_xml2po_modes_docbook.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/modes/docbook.py.orig	2011-01-10 16:08:10.000000000 +0000
+++ xml2po/xml2po/modes/docbook.py
@@ -43,7 +43,7 @@ try:
 except ImportError:
     from md5 import new as md5_new
 
-from basic import basicXmlMode
+from .basic import basicXmlMode
 
 class docbookXmlMode(basicXmlMode):
     """Class for special handling of DocBook document types.
@@ -131,7 +131,7 @@ class docbookXmlMode(basicXmlMode):
                     hash = self._md5_for_file(fullpath)
                 else:
                     hash = "THIS FILE DOESN'T EXIST"
-                    print >>sys.stderr, "Warning: image file '%s' not found." % fullpath
+                    print("Warning: image file '%s' not found." % fullpath, file=sys.stderr)
 
                 msg.outputMessage("@@image: '%s'; md5=%s" % (attr, hash), node.lineNo(),
                                   "When image changes, this message will be marked fuzzy or untranslated for you.\n"+
@@ -184,7 +184,7 @@ class docbookXmlMode(basicXmlMode):
                     else:
                         ai.addChild(copy)
                     if match.group(3):
-                        copy.newChild(None, "year", match.group(3).encode('utf-8'))
+                        copy.newChild(None, "year", match.group(3))
                     if match.group(1) and match.group(2):
                         holder = match.group(1)+"(%s)" % match.group(2)
                     elif match.group(1):
@@ -193,15 +193,15 @@ class docbookXmlMode(basicXmlMode):
                         holder = match.group(2)
                     else:
                         holder = "???"
-                    copy.newChild(None, "holder", holder.encode('utf-8'))
+                    copy.newChild(None, "holder", holder)
 
 # Perform some tests when ran standalone
 if __name__ == '__main__':
     test = docbookXmlMode()
-    print "Ignored tags       : " + repr(test.getIgnoredTags())
-    print "Final tags         : " + repr(test.getFinalTags())
-    print "Space-preserve tags: " + repr(test.getSpacePreserveTags())
+    print("Ignored tags       : " + repr(test.getIgnoredTags()))
+    print("Final tags         : " + repr(test.getFinalTags()))
+    print("Space-preserve tags: " + repr(test.getSpacePreserveTags()))
 
-    print "Credits from string: '%s'" % test.getStringForTranslators()
-    print "Explanation for credits:\n\t'%s'" % test.getCommentForTranslators()
+    print("Credits from string: '%s'" % test.getStringForTranslators())
+    print("Explanation for credits:\n\t'%s'" % test.getCommentForTranslators())
 
