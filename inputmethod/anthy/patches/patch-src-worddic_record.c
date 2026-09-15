$NetBSD: patch-src-worddic_record.c,v 1.1 2026/09/15 13:00:15 wiz Exp $

Treat EOF as the end of a line.  read_1_token reports the end of a line only
on '\n', so when the last line of a record file (~/.anthy/last-record2_*) has
no trailing newline, the loop in read_1_row that reads tokens up to the end
of the line never terminates, and anthy hangs at start-up.

Fedora carries this as anthy-fix-eol.patch (2024), and anthy-unicode has the
same change in src-worddic/record.c.

--- src-worddic/record.c.orig
+++ src-worddic/record.c
@@ -1043,7 +1043,7 @@
   if (s) {
     s[len] = '\0';
   }
-  *eol = (c == '\n');
+  *eol = (c == '\n' || c == EOF);
   return s;
 }
 
