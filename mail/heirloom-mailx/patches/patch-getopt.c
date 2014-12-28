$NetBSD: patch-getopt.c,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

Imported Debian package fixes:
- don't reuse weak symbol optopt to fix FTBFS on mips*

--- getopt.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ getopt.c
@@ -43,7 +43,7 @@ typedef	int	ssize_t;
 char	*optarg;
 int	optind = 1;
 int	opterr = 1;
-int	optopt;
+int	optoptc;
 
 static void
 error(const char *s, int c)
@@ -69,7 +69,7 @@ error(const char *s, int c)
 		*bp++ = *s++;
 	while (*msg)
 		*bp++ = *msg++;
-	*bp++ = optopt;
+	*bp++ = optoptc;
 	*bp++ = '\n';
 	write(2, buf, bp - buf);
 	ac_free(buf);
@@ -101,13 +101,13 @@ getopt(int argc, char *const argv[], con
 		}
 		curp = &argv[optind][1];
 	}
-	optopt = curp[0] & 0377;
+	optoptc = curp[0] & 0377;
 	while (optstring[0]) {
 		if (optstring[0] == ':') {
 			optstring++;
 			continue;
 		}
-		if ((optstring[0] & 0377) == optopt) {
+		if ((optstring[0] & 0377) == optoptc) {
 			if (optstring[1] == ':') {
 				if (curp[1] != '\0') {
 					optarg = (char *)&curp[1];
@@ -127,7 +127,7 @@ getopt(int argc, char *const argv[], con
 					optind++;
 				optarg = 0;
 			}
-			return optopt;
+			return optoptc;
 		}
 		optstring++;
 	}
