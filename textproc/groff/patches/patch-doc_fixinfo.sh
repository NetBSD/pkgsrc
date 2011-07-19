$NetBSD: patch-doc_fixinfo.sh,v 1.1 2011/07/19 21:09:39 tez Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.

--- doc/fixinfo.sh.orig	2009-01-09 14:25:52.000000000 +0000
+++ doc/fixinfo.sh
@@ -21,7 +21,9 @@
 # groff.texinfo macro code.  Hopefully, a new texinfo version makes it
 # unnecessary.
 
-t=${TMPDIR-.}/gro$$.tmp
+t="`mktemp -t groff-fixinfo.XXXXXXXXXX`" || exit
+trap 'rm -f -- "$t"' EXIT
+trap 'trap - EXIT; rm -f -- "$t"; exit 1' HUP INT QUIT TERM
 
 cat $1 | sed '
 1 {
