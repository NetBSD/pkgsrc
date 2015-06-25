$NetBSD: patch-lib_ansible_module__utils_facts.py,v 1.1 2015/06/25 13:21:03 jperkin Exp $

Handle sysctl(8) behaviour in OS X 10.10, using patch from
https://github.com/ansible/ansible/pull/8171/files

--- lib/ansible/module_utils/facts.py.orig	2014-07-25 20:48:49.000000000 +0000
+++ lib/ansible/module_utils/facts.py
@@ -1361,7 +1361,9 @@ class Darwin(Hardware):
         return system_profile
 
     def get_mac_facts(self):
-        self.facts['model'] = self.sysctl['hw.model']
+        rc, out, err = module.run_command("sysctl hw.model")
+        if rc == 0:
+            self.facts['model'] = out.splitlines()[-1].split()[1]
         self.facts['osversion'] = self.sysctl['kern.osversion']
         self.facts['osrevision'] = self.sysctl['kern.osrevision']
 
@@ -1376,7 +1378,10 @@ class Darwin(Hardware):
 
     def get_memory_facts(self):
         self.facts['memtotal_mb'] = long(self.sysctl['hw.memsize']) / 1024 / 1024
-        self.facts['memfree_mb'] = long(self.sysctl['hw.usermem']) / 1024 / 1024
+        rc, out, err = module.run_command("sysctl hw.usermem")
+        if rc == 0:
+            self.facts['memfree_mb'] = long(out.splitlines()[-1].split()[1]) / 1024 / 1024
+
 
 class Network(Facts):
     """
