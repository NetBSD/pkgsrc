$NetBSD: patch-lib_gettext__setup.py,v 1.1 2024/01/28 08:19:19 wiz Exp $

https://github.com/mypaint/mypaint/commit/032a155b72f2b021f66a994050d83f07342d04af

--- lib/gettext_setup.py.orig	2020-02-15 15:05:22.000000000 +0000
+++ lib/gettext_setup.py
@@ -71,13 +71,11 @@ def init_gettext(localepath):
     # yanked in over GI.
     # https://bugzilla.gnome.org/show_bug.cgi?id=574520#c26
     bindtextdomain = None
-    bind_textdomain_codeset = None
     textdomain = None
 
     # Try the POSIX/Linux way first.
     try:
         bindtextdomain = locale.bindtextdomain
-        bind_textdomain_codeset = locale.bind_textdomain_codeset
         textdomain = locale.textdomain
     except AttributeError:
         logger.warning(
@@ -106,12 +104,6 @@ def init_gettext(localepath):
                         ctypes.c_char_p,
                     )
                     bindtextdomain.restype = ctypes.c_char_p
-                    bind_textdomain_codeset = libintl.bind_textdomain_codeset
-                    bind_textdomain_codeset.argtypes = (
-                        ctypes.c_char_p,
-                        ctypes.c_char_p,
-                    )
-                    bind_textdomain_codeset.restype = ctypes.c_char_p
                     textdomain = libintl.textdomain
                     textdomain.argtypes = (
                         ctypes.c_char_p,
@@ -160,35 +152,22 @@ def init_gettext(localepath):
         # complete set from the same source.
         # Required for translatable strings in GtkBuilder XML
         # to be translated.
-        if bindtextdomain and bind_textdomain_codeset and textdomain:
+        if bindtextdomain and textdomain:
             assert os.path.exists(path)
             assert os.path.isdir(path)
             if sys.platform == 'win32':
                 p = bindtextdomain(dom.encode('utf-8'), path.encode('utf-8'))
-                c = bind_textdomain_codeset(
-                    dom.encode('utf-8'), codeset.encode('utf-8')
-                )
             else:
                 p = bindtextdomain(dom, path)
-                c = bind_textdomain_codeset(dom, codeset)
             logger.debug("C bindtextdomain(%r, %r): %r", dom, path, p)
-            logger.debug(
-                "C bind_textdomain_codeset(%r, %r): %r",
-                dom, codeset, c,
-            )
         # Call the implementations in Python's standard gettext module
         # too.  This has proper cross-platform support, but it only
         # initializes the native Python "gettext" module.
         # Required for marked strings in Python source to be translated.
         # See http://docs.python.org/release/2.7/library/locale.html
         p = gettext.bindtextdomain(dom, path)
-        c = gettext.bind_textdomain_codeset(dom, codeset)
         logger.debug("Python bindtextdomain(%r, %r): %r", dom, path, p)
-        logger.debug(
-            "Python bind_textdomain_codeset(%r, %r): %r",
-            dom, codeset, c,
-        )
-    if bindtextdomain and bind_textdomain_codeset and textdomain:
+    if bindtextdomain and textdomain:
         if sys.platform == 'win32':
             d = textdomain(defaultdom.encode('utf-8'))
         else:
