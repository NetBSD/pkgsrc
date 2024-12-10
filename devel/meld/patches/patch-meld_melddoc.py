$NetBSD: patch-meld_melddoc.py,v 1.1 2024/12/10 08:22:10 wiz Exp $

Support Python 3.13.
https://gitlab.gnome.org/GNOME/meld/-/commit/aa817dce6bb0667fc6ef38163c213803dc8b37b3

--- meld/melddoc.py.orig	2024-12-10 08:20:25.370049796 +0000
+++ meld/melddoc.py
@@ -17,7 +17,6 @@
 import enum
 import logging
 import os
-import pipes
 import shlex
 import string
 import subprocess
@@ -45,7 +44,7 @@ def make_custom_editor_command(path: str
         log.error("Unsupported fields found")
         return [custom_command, path]
     else:
-        cmd = custom_command.format(file=pipes.quote(path), line=line)
+        cmd = custom_command.format(file=shlex.quote(path), line=line)
     return shlex.split(cmd)
 
 
