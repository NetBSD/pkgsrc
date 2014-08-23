$NetBSD: patch-mkisofs_mkisofs.c,v 1.1 2014/08/23 05:38:22 wiz Exp $

The bug prevents mkisofs from creating old-style distrib/cdrom ISO
image for macppc.  Trying to create bootable macppc CD in distrib/cdrom
using cdrtools mkisofs fails with:

    mkisofs: No such file or directory. Invalid node - '--macbin'.

The bug is in option spec that causes mkisofs to misparse
-hide-hfs-list option.  The patch is actually a single whitespace
character.

--- mkisofs/mkisofs.c.orig	2014-02-11 22:38:45.000000000 +0000
+++ mkisofs/mkisofs.c
@@ -1364,7 +1364,7 @@ LOCAL const struct mki_option mki_option
 	__("\1FILE\1Set HFS AutoStart file name")},
 	{{"no-desktop%0", &create_dt },
 	__("Do not create the HFS (empty) Desktop files")},
-	{{"hide-hfs&", NULL, (getpargfun)hfs_add_match },
+	{{"hide-hfs& ", NULL, (getpargfun)hfs_add_match },
 	__("\1GLOBFILE\1Hide HFS file")},
 	{{"hide-hfs-list&", NULL, (getpargfun)hfs_add_list },
 	__("\1FILE\1List of HFS files to hide")},
