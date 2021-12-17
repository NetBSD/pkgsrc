$NetBSD: patch-setup.py,v 1.1 2021/12/17 12:43:40 jperkin Exp $

Support PKGMANDIR.

--- setup.py.orig	2021-12-01 00:23:03.000000000 +0000
+++ setup.py
@@ -60,7 +60,7 @@ else:
         ('share/zsh/site-functions', ['completions/zsh/_yt-dlp']),
         ('share/fish/vendor_completions.d', ['completions/fish/yt-dlp.fish']),
         ('share/doc/yt_dlp', ['README.txt']),
-        ('share/man/man1', ['yt-dlp.1'])
+        ('@PKGMANDIR@/man1', ['yt-dlp.1'])
     ]
     root = os.path.dirname(os.path.abspath(__file__))
     data_files = []
