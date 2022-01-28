$NetBSD: patch-etc_afpd_afp__options.c,v 1.2 2022/01/28 21:18:19 nat Exp $

Allow -1 as a vaild tickleval to disable session tickles.
As needed on appletalk 58.

--- etc/afpd/afp_options.c.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/afpd/afp_options.c
@@ -318,7 +318,7 @@ int afp_options_parseline(char *buf, str
         options->loginmaxfail = atoi(c);
     if ((c = getoption(buf, "-tickleval"))) {
         options->tickleval = atoi(c);
-        if (options->tickleval <= 0) {
+        if (options->tickleval < 0) {
             options->tickleval = 30;
         }
     }
