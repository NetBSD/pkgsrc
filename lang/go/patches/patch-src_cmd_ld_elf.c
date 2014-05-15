$NetBSD: patch-src_cmd_ld_elf.c,v 1.2 2014/05/15 20:00:47 christos Exp $

Correctly compute the note size!

--- src/cmd/ld/elf.c.orig	2014-05-15 15:25:59.000000000 -0400
+++ src/cmd/ld/elf.c	2014-05-15 15:25:07.000000000 -0400
@@ -355,7 +355,7 @@
 	sh->addralign = 4;
 	sh->addr = startva + resoff - n;
 	sh->off = resoff - n;
-	sh->size = n;
+	sh->size = n - resoff % 4;
 
 	return n;
 }
@@ -388,7 +388,7 @@
 {
 	int n;
 
-	n = ELF_NOTE_NETBSD_NAMESZ + ELF_NOTE_NETBSD_DESCSZ + 1;
+	n = rnd(ELF_NOTE_NETBSD_NAMESZ, 4) + rnd(ELF_NOTE_NETBSD_DESCSZ, 4);
 	return elfnote(sh, startva, resoff, n);
 }
 
