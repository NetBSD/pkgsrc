$NetBSD: patch-filter_foomatic-rip_foomaticrip.c,v 1.4 2015/06/11 19:13:46 asau Exp $

Adjust according the --with-shell option.

--- filter/foomatic-rip/foomaticrip.c.orig	2015-02-13 22:36:44.000000000 +0000
+++ filter/foomatic-rip/foomaticrip.c
@@ -174,7 +174,7 @@ char cupsfilterpath[PATH_MAX] = "/usr/lo
                                 "/opt/cups/filter:"
                                 "/usr/lib/cups/filter";
 
-char modern_shell[64] = "/bin/bash";
+char modern_shell[64] = SHELL;
 
 void config_set_option(const char *key, const char *value)
 {
