$NetBSD: patch-src_roff_groff_pipeline.c,v 1.1 2011/07/19 21:09:40 tez Exp $

Fix many temporary file handling issues, including in pdfroff
(resolves CVE-2009-5044 / SA44999)
Patches copied from:
 http://cvsweb.openwall.com/cgi/cvsweb.cgi/Owl/packages/groff/groff-1.20.1-owl-tmp.diff?rev=1.2
Modified for pkgsrc and excluded a documentaion change to doc/groff.texinfo
that changes a `makeinfo' is too old warning into a fatal error.

--- src/roff/groff/pipeline.c.orig	2009-01-09 14:25:52.000000000 +0000
+++ src/roff/groff/pipeline.c
@@ -378,6 +378,7 @@ int run_pipeline(int ncommands, char ***
   /* Don't use `tmpnam' here: Microsoft's implementation yields unusable
      file names if current directory is on network share with read-only
      root. */
+#error AUDIT: This code is only compiled under DOS
   tmpfiles[0] = tempnam(tmpdir, NULL);
   tmpfiles[1] = tempnam(tmpdir, NULL);
 
