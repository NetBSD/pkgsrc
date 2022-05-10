$NetBSD: patch-scheduler-conf.c,v 1.3 2022/05/10 20:47:38 markd Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/conf.c.orig	2022-04-29 10:12:16.516789874 +0000
+++ scheduler/conf.c
@@ -140,6 +140,7 @@ static const cupsd_var_t	cupsfiles_vars[
   { "CreateSelfSignedCerts",	&CreateSelfSignedCerts,	CUPSD_VARTYPE_BOOLEAN },
 #endif /* HAVE_TLS */
   { "DataDir",			&DataDir,		CUPSD_VARTYPE_STRING },
+  { "PidFile",			&PidFile,		CUPSD_VARTYPE_STRING },
   { "DocumentRoot",		&DocumentRoot,		CUPSD_VARTYPE_STRING },
   { "ErrorLog",			&ErrorLog,		CUPSD_VARTYPE_STRING },
   { "FileDevice",		&FileDevice,		CUPSD_VARTYPE_BOOLEAN },
@@ -574,6 +575,7 @@ cupsdReadConfiguration(void)
   cupsdSetString(&RequestRoot, CUPS_REQUESTS);
   cupsdSetString(&CacheDir, CUPS_CACHEDIR);
   cupsdSetString(&DataDir, CUPS_DATADIR);
+  cupsdSetString(&PidFile, CUPS_STATEDIR "/cupsd.pid");
   cupsdSetString(&DocumentRoot, CUPS_DOCROOT);
   cupsdSetString(&AccessLog, CUPS_LOGDIR "/access_log");
   cupsdClearString(&ErrorLog);
@@ -3397,6 +3399,7 @@ read_cupsd_conf(cups_file_t *fp)	/* I - 
              !_cups_strcasecmp(line, "CacheDir") ||
              !_cups_strcasecmp(line, "ConfigFilePerm") ||
              !_cups_strcasecmp(line, "DataDir") ||
+             !_cups_strcasecmp(line, "PidFile") ||
              !_cups_strcasecmp(line, "DocumentRoot") ||
              !_cups_strcasecmp(line, "ErrorLog") ||
              !_cups_strcasecmp(line, "FatalErrors") ||
