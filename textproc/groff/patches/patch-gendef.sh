$NetBSD: patch-gendef.sh,v 1.1.2.2 2011/07/21 04:24:07 sbd Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.

--- gendef.sh.orig	2009-01-09 14:25:52.000000000 +0000
+++ gendef.sh
@@ -34,11 +34,9 @@ do
 #define $def"
 done
 
-# Use $TMPDIR if defined.  Default to cwd, for non-Unix systems
-# which don't have /tmp on each drive (we are going to remove
-# the file before we exit anyway).  Put the PID in the basename,
-# since the extension can only hold 3 characters on MS-DOS.
-t=${TMPDIR-.}/gro$$.tmp
+t="`mktemp -t groff-gendef.XXXXXXXXXX`" || exit
+trap 'rm -f -- "$t"' EXIT
+trap 'trap - EXIT; rm -f -- "$t"; exit 1' HUP INT QUIT TERM
 
 sed -e 's/=/ /' >$t <<EOF
 $defs
@@ -46,8 +44,6 @@ EOF
 
 test -r $file && cmp -s $t $file || cp $t $file
 
-rm -f $t
-
 exit 0
 
 # eof
