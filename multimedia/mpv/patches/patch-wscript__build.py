$NetBSD: patch-wscript__build.py,v 1.4 2022/11/16 11:27:32 leot Exp $

Install configuration files to examples, per pkgsrc conventions.

--- wscript_build.py.orig	2022-11-12 13:52:40.000000000 +0000
+++ wscript_build.py
@@ -769,7 +769,7 @@ def build(ctx):
             ctx.env.DATADIR + '/metainfo',
             ['etc/mpv.metainfo.xml'] )
 
-        ctx.install_files(ctx.env.CONFDIR, ['etc/encoding-profiles.conf'] )
+        ctx.install_files(ctx.env.DATADIR + '/examples/mpv', ['etc/encoding-profiles.conf'] )
 
         for size in '16x16 32x32 64x64 128x128'.split():
             ctx.install_as(
