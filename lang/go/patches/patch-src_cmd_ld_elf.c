$NetBSD: patch-src_cmd_ld_elf.c,v 1.1 2014/05/15 19:35:49 christos Exp $

Correctly compute the note size!

--- src/cmd/ld/elf.c.orig	2014-05-15 15:25:59.000000000 -0400
+++ src/cmd/ld/elf.c	2014-05-15 15:25:07.000000000 -0400
@@ -388,7 +388,8 @@
 {
 	int n;
 
-	n = ELF_NOTE_NETBSD_NAMESZ + ELF_NOTE_NETBSD_DESCSZ + 1;
+	n = rnd(ELF_NOTE_NETBSD_NAMESZ, 4) + rnd(ELF_NOTE_NETBSD_DESCSZ, 4);
+	n -= resoff % 4;
 	return elfnote(sh, startva, resoff, n);
 }
 
