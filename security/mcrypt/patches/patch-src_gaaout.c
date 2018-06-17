$NetBSD: patch-src_gaaout.c,v 1.1.2.2 2018/06/17 11:40:03 spz Exp $

* Fix ARM build [XXX needed?]
* Make native format default like in Debian, Red Hat, and SUSE since
  openpgp format handling is seriously broken.

From: Debian, Red Hat, SUSE

--- src/gaaout.c.orig	2007-06-09 08:39:14.000000000 +0000
+++ src/gaaout.c
@@ -5,6 +5,7 @@
 
 
 #include <defines.h>
+#include "mcrypt_int.h"
 
 #include <stdio.h>
 #include <string.h>
@@ -123,7 +124,7 @@ void gaa_help(void)
 {
 	printf(_("Mcrypt encrypts and decrypts files with symmetric encryption algorithms.\nUsage: mcrypt [-dFusgbhLvrzp] [-f keyfile] [-k key1 key2 ...] [-m mode] [-o keymode] [-s keysize] [-a algorithm] [-c config_file] [file ...]\n\n"));
 	__gaa_helpsingle('g', "openpgp", "", _("Use the OpenPGP (RFC2440) file format."));
-	__gaa_helpsingle(0, "no-openpgp", "", _("Use the native (mcrypt) file format."));
+	__gaa_helpsingle(0, "no-openpgp", "", _("Use the native (mcrypt) file format. (DEFAULT)"));
 	__gaa_helpsingle(0, "openpgp-z", _("INTEGER "), _("Sets the compression level for openpgp packets (0 disables)."));
 	__gaa_helpsingle('d', "decrypt", "", _("decrypts."));
 	__gaa_helpsingle('s', "keysize", _("INTEGER "), _("Set the algorithm's key size (in bytes)."));
@@ -1036,7 +1037,7 @@ int gaa(int argc, char **argv, gaainfo *
        gaaval->config_file=NULL; gaaval->mode=NULL; gaaval->input=NULL; gaaval->ed_specified=0;
        gaaval->double_check=0; gaaval->noecho=1; gaaval->flush=0; gaaval->keysize=0;
        gaaval->algorithms_directory=NULL; gaaval->modes_directory=NULL; gaaval->nodelete=0;
-       gaaval->hash=NULL; gaaval->timer=0; gaaval->openpgp=1; gaaval->openpgp_z = 0; ;};
+       gaaval->hash=NULL; gaaval->timer=0; gaaval->openpgp=0; gaaval->openpgp_z = 0; ;};
 
     }
     inited = 1;
