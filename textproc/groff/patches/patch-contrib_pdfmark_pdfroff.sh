$NetBSD: patch-contrib_pdfmark_pdfroff.sh,v 1.2 2011/07/27 16:33:25 tez Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.
Modified to not use '-p' option to mktemp which is missing on some platforms.

Added patch to make pdfroff.sh use -dSAFER
See http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=538338 for why.

--- contrib/pdfmark/pdfroff.sh.orig	2009-01-09 14:25:52.000000000 +0000
+++ contrib/pdfmark/pdfroff.sh
@@ -137,7 +137,15 @@
 #
 # Set up temporary/intermediate file locations.
 #
-  WRKFILE=${GROFF_TMPDIR=${TMPDIR-${TMP-${TEMP-"."}}}}/pdf$$.tmp
+  MYTMPDIR=${GROFF_TMPDIR-${TMPDIR-${TMP-${TEMP-"/tmp"}}}}
+  WRKDIR="`TMPDIR=$MYTMPDIR mktemp -d -t groff-pdfroff.XXXXXXXXXX`" || exit
+
+  trap 'rm -rf -- "$WRKDIR"' EXIT
+  trap 'trap - EXIT; rm -rf -- "$WRKDIR"; exit 1' HUP INT QUIT PIPE TERM
+
+  GROFF_TMPDIR=${WRKDIR}
+
+  WRKFILE=${GROFF_TMPDIR}/pdf$$.tmp
 #
   REFCOPY=${GROFF_TMPDIR}/pdf$$.cmp
   REFFILE=${GROFF_TMPDIR}/pdf$$.ref
@@ -146,11 +154,6 @@
   TC_DATA=${GROFF_TMPDIR}/pdf$$.tc
   BD_DATA=${GROFF_TMPDIR}/pdf$$.ps
 #
-# Set a trap, to delete temporary files on exit.
-# (FIXME: may want to include other signals, in released version).
-#
-  trap "rm -f ${GROFF_TMPDIR}/pdf$$.*" 0
-#
 # Initialise 'groff' format control settings,
 # to discriminate table of contents and document body formatting passes.
 #
@@ -597,7 +600,7 @@
   $SAY >&2 $n "Writing PDF output ..$c"
   if test -z "$PDFROFF_POSTPROCESSOR_COMMAND"
   then
-    PDFROFF_POSTPROCESSOR_COMMAND="$GS -dQUIET -dBATCH -dNOPAUSE
+    PDFROFF_POSTPROCESSOR_COMMAND="$GS -dQUIET -dBATCH -dNOPAUSE -dSAFER
       -sDEVICE=pdfwrite -sOutputFile="${PDF_OUTPUT-"-"}
 
   elif test -n "$PDF_OUTPUT"
