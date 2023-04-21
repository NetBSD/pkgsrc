$NetBSD: patch-opendkim_opendkim-config.h,v 1.1 2023/04/21 13:03:09 manu Exp $

Add OmitHeadersDB directive to specify file containing per-recipient 
list of headers to not use in signature. The file format is:

user@doamin.tld	header1,header2,header3
domain.tld	header4,header5

From upstream https://github.com/trusteddomainproject/OpenDKIM/pull/173

--- opendkim/opendkim-config.h.orig
+++ opendkim/opendkim-config.h
@@ -114,8 +114,9 @@
 	{ "MustBeSigned",		CONFIG_TYPE_STRING,	FALSE },
 	{ "Nameservers",		CONFIG_TYPE_STRING,	FALSE },
 	{ "NoHeaderB",			CONFIG_TYPE_BOOLEAN,	FALSE },
 	{ "OmitHeaders",		CONFIG_TYPE_STRING,	FALSE },
+	{ "OmitHeadersDB",		CONFIG_TYPE_STRING,	FALSE },
 	{ "On-BadSignature",		CONFIG_TYPE_STRING,	FALSE },
 	{ "On-Default",			CONFIG_TYPE_STRING,	FALSE },
 	{ "On-DNSError",		CONFIG_TYPE_STRING,	FALSE },
 	{ "On-InternalError",		CONFIG_TYPE_STRING,	FALSE },
