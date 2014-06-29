$NetBSD: patch-xfile.hc,v 1.1 2014/06/29 04:10:55 dholland Exp $

Fix tautological comparison.

--- xfile.hc~	2014-06-29 04:04:06.000000000 +0000
+++ xfile.hc
@@ -339,7 +339,7 @@ bool bscanf (FILE *f, int num_bytes, int
 
 .  get_byte
      {c.b     = 0;
-      was_eof = ((c.a.b3 = fgetc (f)) == EOF);
+      was_eof = (t = fgetc (f), c.a.b3 = t, t == EOF);
       i       = c.b;
      }.
 
