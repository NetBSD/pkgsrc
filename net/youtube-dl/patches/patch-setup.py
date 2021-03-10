$NetBSD: patch-setup.py,v 1.3 2021/03/10 16:41:22 jperkin Exp $

Fix paths.

--- setup.py.orig	2015-12-10 10:06:06.000000000 +0000
+++ setup.py
@@ -46,10 +46,10 @@ if len(sys.argv) >= 2 and sys.argv[1] ==
     params = py2exe_params
 else:
     files_spec = [
-        ('etc/bash_completion.d', ['youtube-dl.bash-completion']),
-        ('etc/fish/completions', ['youtube-dl.fish']),
+        ('share/bash-completion/completions', ['youtube-dl']),
+        ('share/fish/completions', ['youtube-dl.fish']),
         ('share/doc/youtube_dl', ['README.txt']),
-        ('share/man/man1', ['youtube-dl.1'])
+        ('@PKGMANDIR@/man1', ['youtube-dl.1'])
     ]
     root = os.path.dirname(os.path.abspath(__file__))
     data_files = []
