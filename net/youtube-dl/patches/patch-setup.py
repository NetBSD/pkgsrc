$NetBSD: patch-setup.py,v 1.1 2015/12/10 11:11:16 adam Exp $

Fix paths.

--- setup.py.orig	2015-12-10 10:06:06.000000000 +0000
+++ setup.py
@@ -46,10 +46,10 @@ if len(sys.argv) >= 2 and sys.argv[1] ==
     params = py2exe_params
 else:
     files_spec = [
-        ('etc/bash_completion.d', ['youtube-dl.bash-completion']),
-        ('etc/fish/completions', ['youtube-dl.fish']),
+        ('share/bash_completion.d', ['youtube-dl.bash-completion']),
+        ('share/fish/completions', ['youtube-dl.fish']),
         ('share/doc/youtube_dl', ['README.txt']),
-        ('share/man/man1', ['youtube-dl.1'])
+        ('man/man1', ['youtube-dl.1'])
     ]
     root = os.path.dirname(os.path.abspath(__file__))
     data_files = []
