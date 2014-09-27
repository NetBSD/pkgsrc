$NetBSD: patch-setup.py,v 1.4 2014/09/27 09:46:24 jperkin Exp $

Handle all non-Windows the same for pkgsrc,
in particular do not handle OS X differently.

Fix script name in install rule.
https://sourceforge.net/p/luma/bugs/47/

--- setup.py.orig	2011-05-25 12:32:02.000000000 +0000
+++ setup.py
@@ -146,7 +146,7 @@ if sys.platform.lower().startswith('win'
     )
 
 # Mac OS X
-elif sys.platform.lower().startswith('darwin'):
+elif sys.platform.lower().startswith('darwin_not_in_pkgsrc'):
     # TODO: add Mac OS X spesifics. (py2app?)
 
     # Create the Nroff man page for mac.
@@ -159,7 +159,7 @@ elif sys.platform.lower().startswith('da
     )
 
 # Linux
-elif sys.platform.lower().startswith('linux'):
+else:
     # Include the application icon in various sizes, so that icon themers
     # can change this as per the iconthemeing standards defined by
     # freedesktop.org
@@ -183,7 +183,7 @@ elif sys.platform.lower().startswith('li
 
     _extras = dict(
         data_files=_data_files,
-        scripts=['bin/luma']
+        scripts=['luma/luma.py']
     )
 
 if __name__ == '__main__':
