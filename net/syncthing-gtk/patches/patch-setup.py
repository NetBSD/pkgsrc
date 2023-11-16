$NetBSD: patch-setup.py,v 1.3 2023/11/16 12:16:04 wiz Exp $

Accept a missing git binary.

--- setup.py.orig	2023-11-16 12:08:01.063349216 +0000
+++ setup.py
@@ -19,7 +19,7 @@ def get_version():
     try:
         version = subprocess.check_output(["git", "describe", "--tags"])
         version = version.decode("utf-8").strip("\n\r \t")
-    except subprocess.CalledProcessError:
+    except (subprocess.CalledProcessError, FileNotFoundError):
         # Git-describe method failed, try to guess from working directory name
         project_dir_name = Path(__file__).parent.name
         result = re.match(r"syncthing-gtk-(.*)", project_dir_name)
