$NetBSD: patch-extern.h,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

Imported Debian package fixes:
- unpack: disable option processing for email addresses when calling sendmail

--- extern.h.orig	2011-04-26 21:23:22.000000000 +0000
+++ extern.h
@@ -396,7 +396,7 @@ struct name *outof(struct name *names, F
 int is_fileaddr(char *name);
 struct name *usermap(struct name *names);
 struct name *cat(struct name *n1, struct name *n2);
-char **unpack(struct name *np);
+char **unpack(struct name *smopts, struct name *np);
 struct name *elide(struct name *names);
 int count(struct name *np);
 struct name *delete_alternates(struct name *np);
