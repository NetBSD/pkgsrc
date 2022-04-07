$NetBSD: patch-nss_cmd_certutil_certutil.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/cmd/certutil/certutil.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/cmd/certutil/certutil.c
@@ -3977,7 +3977,7 @@ shutdown:
             newargv[1] = nextcommand;
             nextarg = nextcommand;
             while ((space = PORT_Strpbrk(nextarg, " \f\n\r\t\v"))) {
-                while (isspace(*space)) {
+                while (isspace((unsigned char)*space)) {
                     *space = '\0';
                     space++;
                 }
