$NetBSD: patch-setup.py,v 1.1 2025/05/10 12:07:33 gdt Exp $

Remediate upstream placing bash completion scripts at wheel root.
(Installing them in the right location is left as an exercise for
someone who knows where they belong and cares about completion
scripts.)

https://github.com/magic-wormhole/magic-wormhole/issues/619

--- setup.py.orig	2025-02-20 23:09:35.000000000 +0000
+++ setup.py
@@ -38,7 +38,6 @@ setup(name="magic-wormhole",
                 "wormhole.test",
                 "wormhole.test.dilate",
                 ],
-      data_files=[(".", ["wormhole_complete.bash", "wormhole_complete.zsh", "wormhole_complete.fish"])],
       entry_points={
           "console_scripts":
           [
