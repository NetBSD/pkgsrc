$NetBSD: patch-duplicity_backends_lftpbackend.py,v 1.1 2024/05/24 15:08:39 triaxx Exp $

Replace lftp executable name by absolute path.

--- duplicity/backends/lftpbackend.py.orig	2024-05-24 06:47:44.796435030 +0000
+++ duplicity/backends/lftpbackend.py
@@ -51,7 +51,7 @@ class LFTPBackend(duplicity.backend.Back
 
         # we expect an output
         try:
-            p = os.popen("lftp --version")
+            p = os.popen("@LFTP@ --version")
             fout = p.read()
             ret = p.close()
         except Exception:
@@ -145,7 +145,7 @@ class LFTPBackend(duplicity.backend.Back
         if isinstance(remote_filename, bytes):
             remote_filename = os.fsdecode(remote_filename)
         commandline = (
-            f'lftp -c "source {self.tempname}; mkdir -p -f {cmd_quote(self.remote_path)}; '
+            f'@LFTP@ -c "source {self.tempname}; mkdir -p -f {cmd_quote(self.remote_path)}; '
             f"put {cmd_quote(source_path.uc_name)} "
             f'-o {cmd_quote(self.remote_path) + os.fsdecode(remote_filename)}"'
         )
@@ -159,7 +159,7 @@ class LFTPBackend(duplicity.backend.Back
         if isinstance(remote_filename, bytes):
             remote_filename = os.fsdecode(remote_filename)
         commandline = (
-            f'lftp -c "source {cmd_quote(self.tempname)}; '
+            f'@LFTP@ -c "source {cmd_quote(self.tempname)}; '
             f"get {cmd_quote(self.remote_path) + remote_filename} "
             f'-o {cmd_quote(local_path.uc_name)}"'
         )
@@ -176,7 +176,7 @@ class LFTPBackend(duplicity.backend.Back
         quoted_path = cmd_quote(self.remote_path)
         # failing to cd into the folder might be because it was not created already
         commandline = (
-            f'lftp -c "source {cmd_quote(self.tempname)}; ( cd {quoted_path} && ls ) || '
+            f'@LFTP@ -c "source {cmd_quote(self.tempname)}; ( cd {quoted_path} && ls ) || '
             f'( mkdir -p -f {quoted_path} && cd {quoted_path} && ls )"'
         )
         log.Debug(f"CMD: {commandline}")
@@ -189,7 +189,7 @@ class LFTPBackend(duplicity.backend.Back
 
     def _delete(self, filename):
         commandline = (
-            f'lftp -c "source {cmd_quote(self.tempname)}; cd {cmd_quote(self.remote_path)}; '
+            f'@LFTP@ -c "source {cmd_quote(self.tempname)}; cd {cmd_quote(self.remote_path)}; '
             f'rm {cmd_quote(os.fsdecode(filename))}"'
         )
         log.Debug(f"CMD: {commandline}")
