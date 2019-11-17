$NetBSD: patch-scheduler-conf.c,v 1.2 2019/11/17 21:22:03 leot Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/conf.c.orig	2019-11-17 12:21:47.927540703 +0000
+++ scheduler/conf.c
@@ -142,6 +142,7 @@ static const cupsd_var_t	cupsfiles_vars[
   { "CreateSelfSignedCerts",	&CreateSelfSignedCerts,	CUPSD_VARTYPE_BOOLEAN },
 #endif /* HAVE_SSL */
   { "DataDir",			&DataDir,		CUPSD_VARTYPE_STRING },
+  { "PidFile",			&PidFile,		CUPSD_VARTYPE_STRING },
   { "DocumentRoot",		&DocumentRoot,		CUPSD_VARTYPE_STRING },
   { "ErrorLog",			&ErrorLog,		CUPSD_VARTYPE_STRING },
   { "FileDevice",		&FileDevice,		CUPSD_VARTYPE_BOOLEAN },
@@ -579,6 +580,7 @@ cupsdReadConfiguration(void)
   cupsdSetString(&RequestRoot, CUPS_REQUESTS);
   cupsdSetString(&CacheDir, CUPS_CACHEDIR);
   cupsdSetString(&DataDir, CUPS_DATADIR);
+  cupsdSetString(&PidFile, CUPS_STATEDIR "/cupsd.pid");
   cupsdSetString(&DocumentRoot, CUPS_DOCROOT);
   cupsdSetString(&AccessLog, CUPS_LOGDIR "/access_log");
   cupsdClearString(&ErrorLog);
@@ -3375,6 +3377,7 @@ read_cupsd_conf(cups_file_t *fp)	/* I - 
              !_cups_strcasecmp(line, "CacheDir") ||
              !_cups_strcasecmp(line, "ConfigFilePerm") ||
              !_cups_strcasecmp(line, "DataDir") ||
+             !_cups_strcasecmp(line, "PidFile") ||
              !_cups_strcasecmp(line, "DocumentRoot") ||
              !_cups_strcasecmp(line, "ErrorLog") ||
              !_cups_strcasecmp(line, "FatalErrors") ||
