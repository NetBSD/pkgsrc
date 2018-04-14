$NetBSD: patch-zenmapCore_Paths.py,v 1.1 2018/04/14 13:04:34 adam Exp $

Prefix is a directory above the executable.

--- zenmapCore/Paths.py.orig	2018-04-14 12:10:04.000000000 +0000
+++ zenmapCore/Paths.py
@@ -155,7 +155,7 @@ def get_prefix():
     else:
         # Normal script execution. Look in the current directory to allow
         # running from the distribution.
-        return os.path.abspath(os.path.dirname(fs_dec(sys.argv[0])))
+        return os.path.abspath(os.path.dirname(os.path.dirname(fs_dec(sys.argv[0]))))
 
 prefix = get_prefix()
 
