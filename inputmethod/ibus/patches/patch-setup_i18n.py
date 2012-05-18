$NetBSD: patch-setup_i18n.py,v 1.2 2012/05/18 11:12:25 obache Exp $

* fix translations fail
 http://code.google.com/p/ibus/issues/detail?id=1453

--- setup/i18n.py.orig	2012-02-02 04:54:54.000000000 +0000
+++ setup/i18n.py
@@ -20,6 +20,7 @@
 # Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 # Boston, MA  02111-1307  USA
 
+import locale
 import gettext
 import os
 
@@ -30,5 +31,13 @@ N_ = lambda a: a
 
 def init():
     localedir = os.getenv("IBUS_LOCALEDIR")
+    # Python's locale module doesn't provide all methods on some
+    # operating systems like FreeBSD
+    try:
+        # for non-standard localedir
+        locale.bindtextdomain(DOMAINNAME, localedir)
+        locale.bind_textdomain_codeset(DOMAINNAME, "UTF-8")
+    except AttributeError:
+        pass
     gettext.bindtextdomain(DOMAINNAME, localedir)
     gettext.bind_textdomain_codeset(DOMAINNAME, "UTF-8")
