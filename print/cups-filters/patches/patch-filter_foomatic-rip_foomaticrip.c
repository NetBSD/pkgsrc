$NetBSD: patch-filter_foomatic-rip_foomaticrip.c,v 1.5 2015/06/14 16:08:04 wiz Exp $

Adjust according the --with-shell option.

Fixed upstream as [Bug 1288]:
https://bugs.linuxfoundation.org/show_bug.cgi?id=1288

--- filter/foomatic-rip/foomaticrip.c.orig	2015-02-13 22:36:44.000000000 +0000
+++ filter/foomatic-rip/foomaticrip.c
@@ -174,7 +174,7 @@ char cupsfilterpath[PATH_MAX] = "/usr/lo
                                 "/opt/cups/filter:"
                                 "/usr/lib/cups/filter";
 
-char modern_shell[64] = "/bin/bash";
+char modern_shell[64] = SHELL;
 
 void config_set_option(const char *key, const char *value)
 {
