$NetBSD: patch-opendmarc_parse.c,v 1.2 2022/05/12 13:49:28 jperkin Exp $

Make sure a trailing brackets corresponds to a leading one.

This fixes the case where the sender e-mail address is user@example.net>
Without this fix, OpenDMARC parses the domain as example.net> and skip
DMARC processing since there is no policy for the domain.

Unfortunately, the MTA or MUA tend to fix the trailing bracket on their
own, letting forged e-mail passing through to user mailboxes.

Submitted upstream https://github.com/trusteddomainproject/OpenDMARC/pull/174

--- opendmarc/parse.c.orig	2021-12-20 06:40:37.000000000 +0000
+++ opendmarc/parse.c
@@ -454,6 +454,11 @@ dmarcf_mail_parse(unsigned char *line, u
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
 
