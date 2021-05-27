$NetBSD: patch-opendmarc_parse.c,v 1.1 2021/05/27 16:52:00 manu Exp $

Make sure a trailing brackets corresponds to a leading one
aaa98f5

This fixes the case where the sender e-mail address is user@example.net>
Without this fix, OpenDMARC parses the domain as example.net> and skip
DMARC processing since there is no policy for the domain.

Unfortunately, the MTA or MUA tend to fix the trailing bracket on their
own, letting forged e-mail passing through to user mailboxes.

Submitted upstream https://github.com/trusteddomainproject/OpenDMARC/pull/174

--- opendmarc/parse.c.orig	2021-05-27 09:45:40.873727663 +0200
+++ opendmarc/parse.c	2021-05-27 09:45:27.545312746 +0200
@@ -444,8 +444,13 @@
 					*w++ = '\0';
 					*domain_out = w;
 					ws = 0;
 				}
+				else if (type == '>')
+				{
+					err = MAILPARSE_ERR_SUNBALANCED;
+					return err;
+				}
 				else
 				{
 
 					if (*user_out == NULL)
