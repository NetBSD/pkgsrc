$NetBSD: patch-src_configobj_validate.py,v 1.1 2023/10/22 10:03:37 wiz Exp $

Fix CVE-2023-26112
From Fedora:
https://src.fedoraproject.org/rpms/python-configobj/raw/rawhide/f/0001-Address-CVE-2023-26112-ReDoS.patch

--- src/configobj/validate.py.orig	2023-01-18 22:28:31.000000000 +0000
+++ src/configobj/validate.py
@@ -541,7 +541,7 @@ class Validator(object):
     """
 
     # this regex does the initial parsing of the checks
-    _func_re = re.compile(r'(.+?)\((.*)\)', re.DOTALL)
+    _func_re = re.compile(r'([^\(\)]+?)\((.*)\)', re.DOTALL)
 
     # this regex takes apart keyword arguments
     _key_arg = re.compile(r'^([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.*)$',  re.DOTALL)
