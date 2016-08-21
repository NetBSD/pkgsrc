$NetBSD: patch-xonsh_aliases.py,v 1.1 2016/08/21 11:34:57 kamil Exp $

Cherry-pick upstream patch adding NetBSD support
https://github.com/xonsh/xonsh/pull/1601

--- xonsh/aliases.py.orig	2016-08-17 00:35:49.000000000 +0000
+++ xonsh/aliases.py
@@ -15,7 +15,7 @@ from xonsh.foreign_shells import foreign
 from xonsh.jobs import jobs, fg, bg, clean_jobs
 from xonsh.history import history_main
 from xonsh.platform import (ON_ANACONDA, ON_DARWIN, ON_WINDOWS, ON_FREEBSD,
-                            scandir)
+                            ON_NETBSD, scandir)
 from xonsh.proc import foreground
 from xonsh.replay import replay_main
 from xonsh.timings import timeit_alias
@@ -593,6 +593,10 @@ def make_default_aliases():
         default_aliases['egrep'] = ['egrep', '--color=auto']
         default_aliases['fgrep'] = ['fgrep', '--color=auto']
         default_aliases['ls'] = ['ls', '-G']
+    elif ON_NETBSD:
+        default_aliases['grep'] = ['grep', '--color=auto']
+        default_aliases['egrep'] = ['egrep', '--color=auto']
+        default_aliases['fgrep'] = ['fgrep', '--color=auto']
     else:
         default_aliases['grep'] = ['grep', '--color=auto']
         default_aliases['egrep'] = ['egrep', '--color=auto']
