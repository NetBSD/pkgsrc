$NetBSD: patch-src_client_rspamc.c,v 1.1 2015/01/17 17:34:07 wiedi Exp $
the struct dirent d_type is not available on SunOS

--- src/client/rspamc.c.orig	2014-12-22 17:57:39.000000000 +0000
+++ src/client/rspamc.c
@@ -853,6 +853,9 @@ rspamc_process_dir (struct event_base *e
 	DIR *d;
 	gint cur_req = 0;
 	struct dirent *ent;
+#if defined(__sun)
+	struct stat sb;
+#endif
 	FILE *in;
 	char filebuf[PATH_MAX];
 
@@ -860,9 +863,14 @@ rspamc_process_dir (struct event_base *e
 
 	if (d != NULL) {
 		while ((ent = readdir (d))) {
+			rspamd_snprintf (filebuf, sizeof (filebuf), "%s%c%s",
+					name, G_DIR_SEPARATOR, ent->d_name);
+#if defined(__sun)
+			if (stat (filebuf, &sb)) continue;
+			if (S_ISREG (sb.st_mode)) {
+#else
 			if (ent->d_type == DT_REG || ent->d_type == DT_UNKNOWN) {
-				rspamd_snprintf (filebuf, sizeof (filebuf), "%s%c%s",
-						name, G_DIR_SEPARATOR, ent->d_name);
+#endif
 				if (access (filebuf, R_OK) != -1) {
 					in = fopen (filebuf, "r");
 					if (in == NULL) {
