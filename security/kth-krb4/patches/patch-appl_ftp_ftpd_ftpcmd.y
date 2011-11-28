$NetBSD: patch-appl_ftp_ftpd_ftpcmd.y,v 1.1 2011/11/28 19:33:13 marino Exp $

--- appl/ftp/ftpd/ftpcmd.y.orig	2001-08-05 06:39:29.000000000 +0000
+++ appl/ftp/ftpd/ftpcmd.y
@@ -103,7 +103,7 @@ static int		 yylex (void);
 	UMASK	IDLE	CHMOD
 
 	AUTH	ADAT	PROT	PBSZ	CCC	MIC
-	CONF	ENC
+	CNFX	ENC
 
 	KAUTH	KLIST	KDESTROY KRBTKFILE AFSLOG
 	LOCATE	URL
@@ -695,7 +695,7 @@ rcmd
 			mec($3, prot_safe);
 			free($3);
 		}
-	| CONF SP STRING CRLF
+	| CNFX SP STRING CRLF
 		{
 			mec($3, prot_confidential);
 			free($3);
@@ -984,7 +984,7 @@ struct tab cmdtab[] = {		/* In order def
 	{ "PROT", PROT,	STR1, 1,	"<sp> prot-level" },
 	{ "CCC",  CCC,	ARGS, 1,	"" },
 	{ "MIC",  MIC,	STR1, 1,	"<sp> integrity command" },
-	{ "CONF", CONF,	STR1, 1,	"<sp> confidentiality command" },
+	{ "CONF", CNFX,	STR1, 1,	"<sp> confidentiality command" },
 	{ "ENC",  ENC,	STR1, 1,	"<sp> privacy command" },
 
 	/* RFC2389 */
