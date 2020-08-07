$NetBSD: patch-lib_ansible_module__utils_facts_hardware_netbsd.py,v 1.1 2020/08/07 07:40:41 maya Exp $

use mount(8) to get run-time file systems instead of boot-time /etc/fstab

--- lib/ansible/module_utils/facts/hardware/netbsd.py.orig	2020-07-21 01:08:10.000000000 +0000
+++ lib/ansible/module_utils/facts/hardware/netbsd.py
@@ -116,20 +116,23 @@ class NetBSDHardware(Hardware):
         mount_facts = {}
 
         mount_facts['mounts'] = []
-        fstab = get_file_content('/etc/fstab')
+        mount_cmd = self.module.get_bin_path('mount')
 
-        if not fstab:
+        if not mount_cmd:
             return mount_facts
 
-        for line in fstab.splitlines():
-            if line.startswith('#') or line.strip() == '':
-                continue
+        rc, mount_out, err = self.module.run_command(mount_cmd)
+        if rc != 0:
+            return mount_facts
+
+        for line in mount_out.splitlines():
             fields = re.sub(r'\s+', ' ', line).split()
-            mount_statvfs_info = get_mount_size(fields[1])
-            mount_info = {'mount': fields[1],
+            mount_statvfs_info = get_mount_size(fields[2])
+            mount_options = line[line.find("(")+1 : line.find(")")].replace(" ","")
+            mount_info = {'mount': fields[2],
                           'device': fields[0],
-                          'fstype': fields[2],
-                          'options': fields[3]}
+                          'fstype': fields[4],
+                          'options': mount_options}
             mount_info.update(mount_statvfs_info)
             mount_facts['mounts'].append(mount_info)
         return mount_facts
