$NetBSD: patch-report.c,v 1.1 2013/07/04 03:41:48 dholland Exp $

Don't print time_t with %lu; it fails on 32-bit netbsd, where time_t is
wider than that.

--- report.c~	2013-05-13 15:22:54.000000000 +0000
+++ report.c
@@ -343,10 +343,10 @@ void csv_close(time_t now)
     if(!ipinfo_no) {
       char* fmtinfo = fmt_ipinfo(addr);
       if (fmtinfo != NULL) fmtinfo = trim(fmtinfo);
-      printf("MTR.%s;%lu;%s;%s;%d;%s;%s;%d", MTR_VERSION, now, "OK", Hostname,
+      printf("MTR.%s;%lld;%s;%s;%d;%s;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
              at+1, name, fmtinfo, last);
     } else {
-      printf("MTR.%s;%lu;%s;%s;%d;%s;%d", MTR_VERSION, now, "OK", Hostname,
+      printf("MTR.%s;%lld;%s;%s;%d;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
              at+1, name, last);
     }
 
