$NetBSD: patch-scheduler-conf.c,v 1.1 2017/07/27 08:54:26 wiz Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/conf.c.orig	2017-03-28 20:26:53.000000000 +0200
+++ scheduler/conf.c	2017-07-17 18:04:23.000000000 +0200
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
@@ -3402,6 +3404,7 @@ read_cupsd_conf(cups_file_t *fp)	/* I - 
              !_cups_strcasecmp(line, "CacheDir") ||
              !_cups_strcasecmp(line, "ConfigFilePerm") ||
              !_cups_strcasecmp(line, "DataDir") ||
+             !_cups_strcasecmp(line, "PidFile") ||
              !_cups_strcasecmp(line, "DocumentRoot") ||
              !_cups_strcasecmp(line, "ErrorLog") ||
              !_cups_strcasecmp(line, "FatalErrors") ||
