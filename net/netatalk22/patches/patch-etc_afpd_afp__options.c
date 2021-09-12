$NetBSD: patch-etc_afpd_afp__options.c,v 1.1 2021/09/12 15:52:37 nat Exp $

Allow -1 as a vaild tickleval to disable session tickles.
As needed on appletalk 58.

--- etc/afpd/afp_options.c.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/afpd/afp_options.c
@@ -318,7 +318,7 @@ int afp_options_parseline(char *buf, str
         options->loginmaxfail = atoi(c);
     if ((c = getoption(buf, "-tickleval"))) {
         options->tickleval = atoi(c);
-        if (options->tickleval <= 0) {
+        if (options->tickleval != -1 && options->tickleval <= 0) {
             options->tickleval = 30;
         }
     }
