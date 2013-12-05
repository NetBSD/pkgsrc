$NetBSD: patch-ext_date_lib_parse__iso__intervals.re,v 1.1 2013/12/05 16:17:48 taca Exp $

Fix for CVE-2013-6712.

--- ext/date/lib/parse_iso_intervals.re.orig	2013-11-12 14:17:27.000000000 +0000
+++ ext/date/lib/parse_iso_intervals.re
@@ -348,7 +348,7 @@ isoweek          = year4 "-"? "W" weekof
 					break;
 			}
 			ptr++;
-		} while (*ptr);
+		} while (!s->errors->error_count && *ptr);
 		s->have_period = 1;
 		TIMELIB_DEINIT;
 		return TIMELIB_PERIOD;
