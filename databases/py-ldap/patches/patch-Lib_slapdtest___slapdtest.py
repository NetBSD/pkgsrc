$NetBSD: patch-Lib_slapdtest___slapdtest.py,v 1.1 2022/05/10 16:58:03 adam Exp $

Fix test: look for slapadd in sbin.

--- Lib/slapdtest/_slapdtest.py.orig	2022-05-10 16:52:41.000000000 +0000
+++ Lib/slapdtest/_slapdtest.py
@@ -259,7 +259,7 @@ class SlapdObject:
         self.PATH_LDAPDELETE = self._find_command('ldapdelete')
         self.PATH_LDAPMODIFY = self._find_command('ldapmodify')
         self.PATH_LDAPWHOAMI = self._find_command('ldapwhoami')
-        self.PATH_SLAPADD = self._find_command('slapadd')
+        self.PATH_SLAPADD = self._find_command('slapadd', in_sbin=True)
 
         self.PATH_SLAPD = os.environ.get('SLAPD', None)
         if not self.PATH_SLAPD:
