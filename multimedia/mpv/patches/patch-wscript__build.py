$NetBSD: patch-wscript__build.py,v 1.3 2022/05/03 07:04:27 nia Exp $

Install configuration files to examples, per pkgsrc conventions.

--- wscript_build.py.orig	2022-01-03 19:45:08.000000000 +0000
+++ wscript_build.py
@@ -737,7 +737,7 @@ def build(ctx):
             ctx.env.DATADIR + '/applications',
             ['etc/mpv.desktop'] )
 
-        ctx.install_files(ctx.env.CONFDIR, ['etc/encoding-profiles.conf'] )
+        ctx.install_files(ctx.env.DATADIR + '/examples/mpv',  ['etc/encoding-profiles.conf'] )
 
         for size in '16x16 32x32 64x64 128x128'.split():
             ctx.install_as(
