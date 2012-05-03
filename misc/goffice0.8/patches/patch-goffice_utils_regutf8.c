$NetBSD: patch-goffice_utils_regutf8.c,v 1.1 2012/05/03 07:34:33 wiz Exp $

Replace call to obsolete function.

--- goffice/utils/regutf8.c.orig	2009-09-05 23:52:09.000000000 +0000
+++ goffice/utils/regutf8.c
@@ -155,7 +155,7 @@ go_regcomp (GORegexp *gor, const char *p
 		default: return GO_REG_BADPAT;
 		}
 	} else {
-		gor->re_nsub = pcre_info (r, NULL, NULL);
+		pcre_fullinfo (r, NULL, PCRE_INFO_CAPTURECOUNT, &gor->re_nsub);
 		gor->nosub = (cflags & GO_REG_NOSUB) != 0;
 		return 0;
 	}
