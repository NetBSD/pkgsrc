$NetBSD: patch-opendmarc_opendmarc-config.h,v 1.1 2022/05/12 13:49:28 jperkin Exp $

Add RequiredFrom option to reject messages that lack a From header from which
a valid domain can be extracted.

Submitted upstream https://github.com/trusteddomainproject/OpenDMARC/pull/147

--- opendmarc/opendmarc-config.h.orig	2021-12-20 06:40:37.000000000 +0000
+++ opendmarc/opendmarc-config.h
@@ -45,6 +45,7 @@ struct configdef dmarcf_config[] =
 	{ "PublicSuffixList",		CONFIG_TYPE_STRING,	FALSE },
 	{ "RecordAllMessages",		CONFIG_TYPE_BOOLEAN,	FALSE },
 	{ "RequiredHeaders",		CONFIG_TYPE_BOOLEAN,	FALSE },
+	{ "RequiredFrom",		CONFIG_TYPE_BOOLEAN,	FALSE },
 	{ "RejectFailures",		CONFIG_TYPE_BOOLEAN,	FALSE },
 	{ "RejectMultiValueFrom",	CONFIG_TYPE_BOOLEAN,	FALSE },
 	{ "ReportCommand",		CONFIG_TYPE_STRING,	FALSE },
