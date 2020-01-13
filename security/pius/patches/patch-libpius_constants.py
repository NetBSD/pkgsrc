$NetBSD: patch-libpius_constants.py,v 1.1 2020/01/13 20:52:04 schmonz Exp $

Use pkgsrc paths.

--- libpius/constants.py.orig	2019-07-05 21:11:13.000000000 +0000
+++ libpius/constants.py
@@ -7,7 +7,7 @@ VERSION = "3.0.0"
 
 HOME = os.environ.get("HOME")
 GNUPGHOME = os.environ.get("GNUPGHOME", os.path.join(HOME, ".gnupg"))
-DEFAULT_GPG_PATH = "/usr/bin/gpg2"
+DEFAULT_GPG_PATH = "@PREFIX@/bin/gpg2"
 DEFAULT_KEYRING = os.path.join(GNUPGHOME, "pubring.gpg")
 DEFAULT_TMP_DIR = "/tmp/pius_tmp"
 DEFAULT_OUT_DIR = "/tmp/pius_out"
