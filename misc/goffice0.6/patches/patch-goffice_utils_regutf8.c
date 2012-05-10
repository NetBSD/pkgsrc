$NetBSD: patch-goffice_utils_regutf8.c,v 1.1 2012/05/10 04:43:53 dholland Exp $

Replace call to obsolete function.

--- goffice/utils/regutf8.c~	2008-07-08 09:54:59.000000000 +0000
+++ goffice/utils/regutf8.c
@@ -155,7 +155,7 @@ go_regcomp (GORegexp *gor, const char *p
 		default: return REG_BADPAT;
 		}
 	} else {
-		gor->re_nsub = pcre_info (r, NULL, NULL);
+		pcre_fullinfo (r, NULL, PCRE_INFO_CAPTURECOUNT, &gor->re_nsub);
 		gor->nosub = (cflags & REG_NOSUB) != 0;
 		return 0;
 	}
