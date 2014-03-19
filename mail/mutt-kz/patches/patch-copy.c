$NetBSD: patch-copy.c,v 1.1 2014/03/19 16:17:38 wiz Exp $

Fix buffer overrun caused by not updating a string length after
address expansion.
http://dev.mutt.org/hg/mutt/rev/9bf7593e3c08

--- copy.c.orig	2013-11-14 10:03:28.000000000 +0000
+++ copy.c
@@ -258,6 +258,7 @@ mutt_copy_hdr (FILE *in, FILE *out, LOFF
     {
       if (!address_header_decode (&this_one))
 	rfc2047_decode (&this_one);
+	this_one_len = mutt_strlen (this_one);
     }
     
     if (!headers[x])
