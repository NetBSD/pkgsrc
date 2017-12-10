$NetBSD: patch-gtkdoc.py,v 1.2 2017/12/10 16:02:59 bsiegert Exp $

--- gtkdoc.py.orig	2017-11-12 18:14:32.000000000 +0000
+++ gtkdoc.py
@@ -196,12 +196,12 @@ class GTKDoc(object):
             if stdout:
                 try:
                     sys.stdout.write(stdout.encode("utf-8"))
-                except UnicodeDecodeError:
+                except (TypeError, UnicodeDecodeError):
                     sys.stdout.write(stdout)
             if stderr:
                 try:
                     sys.stderr.write(stderr.encode("utf-8"))
-                except UnicodeDecodeError:
+                except (TypeError, UnicodeDecodeError):
                     sys.stderr.write(stderr)
 
         if process.returncode != 0:
@@ -223,6 +223,9 @@ class GTKDoc(object):
             return
 
         def copy_file_replacing_existing(src, dest):
+            if src == dest:
+               self.logger.debug('copy_file_replacing_existing not copying to itself: %s', src)
+               return
             if os.path.isdir(src):
                 self.logger.debug('skipped directory %s',  src)
                 return
