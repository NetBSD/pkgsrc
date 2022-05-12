$NetBSD: patch-opendmarc_opendmarc.c,v 1.1 2022/05/12 13:49:28 jperkin Exp $

Add RequiredFrom option to reject messages that lack a From header from which
a valid domain can be extracted.

Submitted upstream https://github.com/trusteddomainproject/OpenDMARC/pull/147

--- opendmarc/opendmarc.c.orig	2021-12-20 06:40:37.000000000 +0000
+++ opendmarc/opendmarc.c
@@ -164,6 +164,7 @@ typedef struct dmarcf_connctx * DMARCF_C
 struct dmarcf_config
 {
 	_Bool			conf_reqhdrs;
+	_Bool			conf_reqfrom;
 	_Bool			conf_afrf;
 	_Bool			conf_afrfnone;
 	_Bool			conf_rejectfail;
@@ -1423,6 +1424,10 @@ dmarcf_config_load(struct config *data,
 		                  &conf->conf_reqhdrs,
 		                  sizeof conf->conf_reqhdrs);
 
+		(void) config_get(data, "RequiredFrom",
+		                  &conf->conf_reqfrom,
+		                  sizeof conf->conf_reqfrom);
+
 		(void) config_get(data, "FailureReports",
 		                  &conf->conf_afrf,
 		                  sizeof conf->conf_afrf);
@@ -2455,11 +2460,15 @@ mlfi_eom(SMFICTX *ctx)
 		if (conf->conf_dolog)
 		{
 			syslog(LOG_INFO,
-			       "%s: RFC5322 requirement error: missing From field; accepting",
-			       dfc->mctx_jobid);
+			       "%s: RFC5322 requirement error: missing From field; %s",
+			       dfc->mctx_jobid,
+			       conf->conf_reqfrom ? "reject" : "accepting");
 		}
 
-		return SMFIS_ACCEPT;
+		if (conf->conf_reqfrom)
+			return SMFIS_REJECT;
+		else
+			return SMFIS_ACCEPT;
 	}
 
 	/* extract From: addresses */
@@ -2499,11 +2508,11 @@ mlfi_eom(SMFICTX *ctx)
 		if (conf->conf_dolog)
 		{
 			syslog(LOG_ERR,
-			       "%s: unable to parse From header field",
-			       dfc->mctx_jobid);
+			       "%s: unable to parse From header field \"%s\"",
+			       dfc->mctx_jobid, from->hdr_value);
 		}
 
-		if (conf->conf_reqhdrs)
+		if (conf->conf_reqhdrs || conf->conf_reqfrom) 
 			return SMFIS_REJECT;
 		else
 			return SMFIS_ACCEPT;
