$NetBSD: patch-names.c,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

Imported Debian package fixes:
- document that address expansion is disabled unless the expandaddr
  binary option is set.  This has been assigned CVE-2014-7844 for
  BSD mailx, but it is not a vulnerability in Heirloom mailx because
  this feature was documented.

- disable option processing for email addresses when calling sendmail

Change "send-mail" to "sendmail" to match /etc/mailer.conf

--- names.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ names.c
@@ -268,6 +268,9 @@ outof(struct name *names, FILE *fo, stru
 	FILE *fout, *fin;
 	int ispipe;
 
+        if (value("expandaddr") == NULL)
+                return names;
+
 	top = names;
 	np = names;
 	time(&now);
@@ -546,7 +549,7 @@ cat(struct name *n1, struct name *n2)
  * Return an error if the name list won't fit.
  */
 char **
-unpack(struct name *np)
+unpack(struct name *smopts, struct name *np)
 {
 	char **ap, **top;
 	struct name *n;
@@ -572,7 +575,7 @@ unpack(struct name *np)
 	/*LINTED*/
 	top = (char **)salloc((t + extra) * sizeof *top);
 	ap = top;
-	*ap++ = "send-mail";
+	*ap++ = "sendmail";
 	*ap++ = "-i";
 	if (metoo)
 		*ap++ = "-m";
