$NetBSD: patch-src_mcrypt.c,v 1.1.2.2 2018/06/17 11:40:03 spz Exp $

* Fix potential long filename buffer overlow (CVE-2012-4527)

From: Debian, Red Hat, SUSE

--- src/mcrypt.c.orig	2007-11-07 17:10:21.000000000 +0000
+++ src/mcrypt.c
@@ -46,3 +46,3 @@ static char rcsid[] =
 
-char tmperr[128];
+char tmperr[PATH_MAX + 128];
 unsigned int stream_flag = FALSE;
@@ -484,3 +484,3 @@ int main(int argc, char **argv)
 	 if (is_normal_file(file[i]) == FALSE) {
-	    sprintf(tmperr,
+	    snprintf(tmperr, sizeof(tmperr),
 		    _
@@ -503,3 +503,3 @@ int main(int argc, char **argv)
 	     && (stream_flag == TRUE) && (force == 0)) {	/* not a tty */
-	    sprintf(tmperr,
+	    snprintf(tmperr, sizeof(tmperr),
 		    _
@@ -522,3 +522,3 @@ int main(int argc, char **argv)
 	     && (stream_flag == TRUE) && (force == 0)) {	/* not a tty */
-	    sprintf(tmperr,
+	    snprintf(tmperr, sizeof(tmperr),
 		    _
@@ -546,3 +546,3 @@ int main(int argc, char **argv)
 	    if (strstr(outfile, ".nc") != NULL) {
-	       sprintf(tmperr,
+	       snprintf(tmperr, sizeof(tmperr),
 		       _
@@ -592,3 +592,5 @@ int main(int argc, char **argv)
 	    if (stream_flag == FALSE) {
-	       sprintf(tmperr, _("File %s was decrypted.\n"), dinfile);
+	       snprintf(tmperr, sizeof(tmperr),
+			_
+			("File %s was decrypted.\n"), dinfile);
 	       err_warn(tmperr);
@@ -612,3 +614,3 @@ int main(int argc, char **argv)
 	    if (stream_flag == FALSE) {
-	       sprintf(tmperr,
+	       snprintf(tmperr, sizeof(tmperr),
 		       _
@@ -638,3 +640,5 @@ int main(int argc, char **argv)
 	    if (stream_flag == FALSE) {
-	       sprintf(tmperr, _("File %s was encrypted.\n"), einfile);
+	       snprintf(tmperr, sizeof(tmperr),
+			_
+			("File %s was encrypted.\n"), einfile);
 	       err_warn(tmperr);
@@ -657,3 +661,3 @@ int main(int argc, char **argv)
 	    if (stream_flag == FALSE) {
-	       sprintf(tmperr,
+	       snprintf(tmperr, sizeof(tmperr),
 		       _
