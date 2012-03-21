$NetBSD: patch-texk_web2c_xetexdir_xetex.ch,v 1.1 2012/03/21 22:32:35 markd Exp $

Work with zlib 1.2.6.  From http://trac.macports.org/changeset/89696

--- /local/scratch/pkgsrc/print/xetex/work.debretts/texlive-20110705-source/texk/web2c/xetexdir/xetex.ch.orig	2012-03-12 03:24:10.533956184 +0000
+++ /local/scratch/pkgsrc/print/xetex/work.debretts/texlive-20110705-source/texk/web2c/xetexdir/xetex.ch
@@ -6944,7 +6944,6 @@ if (x<>69069)or feof(fmt_file) then goto
 @y
 undump_int(x);
 if (x<>69069) then goto bad_fmt;
-if not w_eof(fmt_file) then goto bad_fmt
 @z
 
 @x
