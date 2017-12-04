$NetBSD: patch-src_common_get.c,v 1.1 2017/12/04 09:32:01 he Exp $

Ensure args to toxxxx() is within allowed range.

--- src/common/get.c.orig	2017-05-16 15:10:27.000000000 +0000
+++ src/common/get.c
@@ -569,7 +569,7 @@ get_name2addr4(const char *hostname, boo
      *  We only want dots 'n decimals.
      */
     else {
-        if (!isdigit(hostname[0])) {
+        if (!isdigit((unsigned char)hostname[0])) {
             warnx("Expected dotted-quad notation (%s) when DNS lookups are disabled", 
                     hostname);
             /* XXX - this is actually 255.255.255.255 */
