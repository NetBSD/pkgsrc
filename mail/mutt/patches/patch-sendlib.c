$NetBSD: patch-sendlib.c,v 1.1 2015/09/03 14:49:02 wiz Exp $

Fix CVE-2014-9116 using the upstream patch from
http://dev.mutt.org/trac/changeset/0aebf1df43598b442ac75ae4fe17875351854db0

--- sendlib.c.orig	2014-03-12 16:03:45.000000000 +0000
+++ sendlib.c
@@ -1814,7 +1814,14 @@ static int write_one_header (FILE *fp, i
     {
       tagbuf = mutt_substrdup (start, t);
       /* skip over the colon separating the header field name and value */
-      t = skip_email_wsp(t + 1);
+      ++t;
+
+      /* skip over any leading whitespace (WSP, as defined in RFC5322)
+       * NOTE: skip_email_wsp() does the wrong thing here.
+       *       See tickets 3609 and 3716. */
+      while (*t == ' ' || *t == '\t')
+        t++;
+
       valbuf = mutt_substrdup (t, end);
     }
     dprint(4,(debugfile,"mwoh: buf[%s%s] too long, "
