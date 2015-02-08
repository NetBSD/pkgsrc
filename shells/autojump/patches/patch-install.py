$NetBSD: patch-install.py,v 1.2 2015/02/08 17:40:25 wiz Exp $

Remove duplicate mkdirs.
https://github.com/joelthelion/autojump/issues/350

--- install.py.orig	2015-01-25 07:13:20.000000000 +0000
+++ install.py
@@ -175,7 +175,6 @@ def main(args):
 
     mkdir(bin_dir, args.dryrun)
     mkdir(doc_dir, args.dryrun)
-    mkdir(etc_dir, args.dryrun)
     mkdir(share_dir, args.dryrun)
 
     cp('./bin/autojump', bin_dir, args.dryrun)
@@ -197,7 +196,6 @@ def main(args):
             modify_autojump_lua(args.clinkdir, bin_dir, args.dryrun)
     else:
         mkdir(etc_dir, args.dryrun)
-        mkdir(share_dir, args.dryrun)
         mkdir(zshshare_dir, args.dryrun)
 
         cp('./bin/autojump.sh', etc_dir, args.dryrun)
