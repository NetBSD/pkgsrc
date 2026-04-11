$NetBSD: patch-meld_vc___vc.py,v 1.1 2026/04/11 11:39:51 wiz Exp $

Fix some file descriptor/process leaks.
https://gitlab.gnome.org/GNOME/meld/-/issues/960

--- meld/vc/_vc.py.orig	2026-04-11 10:51:10.506439807 +0000
+++ meld/vc/_vc.py
@@ -433,7 +433,7 @@ def call_temp_output(cmd, cwd, file_id='', suffix=None
     of the temporary file's name.
     """
     process = subprocess.Popen(
-        cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
+        cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
         startupinfo=get_hide_window_startupinfo(),
     )
     vc_file = process.stdout
@@ -445,14 +445,15 @@ def call_temp_output(cmd, cwd, file_id='', suffix=None
     with tempfile.NamedTemporaryFile(prefix=prefix,
                                      suffix=suffix, delete=False) as f:
         shutil.copyfileobj(vc_file, f)
+    vc_file.close()
+    process.wait()
     return f.name
 
 
 # Return the return value of a given command
 def call(cmd, cwd=None):
-    devnull = open(os.devnull, "wb")
     return subprocess.call(
-        cmd, cwd=cwd, stdout=devnull, stderr=devnull,
+        cmd, cwd=cwd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
         startupinfo=get_hide_window_startupinfo(),
     )
 
