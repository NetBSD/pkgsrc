$NetBSD: patch-cdda2wav-setuid.c,v 1.3 2020/04/03 08:58:24 hauke Exp $

Joerg Schilling has recently released schilytools-2005-09-16 (1).
Lines 83 to 84 of AN-2015-09-16 (2) mention an issue affecting
unpriviledged users running cdda2wav on NetBSD:

cdda2wav: fixed the file setuid.c to work on NetBSD. Thanks to
Heiko Eissfeldt for reporting.

Hence this "diff -urp cdrtools-3.01/cdda2wav/ schily-2015-09-16/cdda2wav/"

Referencess:
(1) http://sourceforge.net/projects/schilytools/files/AN-2015-09-16
(2) http://downloads.sourceforge.net/project/schilytools/schily-2015-09-16.tar.bz2

--- cdda2wav/setuid.c.orig	2011-08-03 21:08:06.000000000 +0000
+++ cdda2wav/setuid.c
@@ -208,6 +210,9 @@ neverneedroot()
 		errmsgno(EX_BAD, _("Fatal error: initsecurity() not called.\n"));
 		exit(INTERNAL_ERROR);
 	}
+	if (geteuid() != effective_uid) {
+		needroot(1);
+	}
 	if (geteuid() == effective_uid) {
 #if defined(HAVE_SETUID)
 		if (setuid(real_uid)) {
@@ -348,6 +353,9 @@ neverneedgroup()
 		errmsgno(EX_BAD, _("Fatal error: initsecurity() not called.\n"));
 		exit(INTERNAL_ERROR);
 	}
+	if (getegid() != effective_gid) {
+		needgroup(1);
+	}
 	if (getegid() == effective_gid) {
 #if defined(HAVE_SETGID)
 		if (setgid(real_gid)) {
@@ -370,6 +378,12 @@ neverneedgroup()
 	if (getegid() != real_gid || getgid() != real_gid) {
 		errmsgno(EX_BAD,
 			_("Fatal error: did not drop group privilege.\n"));
+#ifdef DEBUG
+		fprintf(stderr,
+		"in  to neverneedgroup (_egid_=%d, gid=%d), current=%d/%d, pid=%d\n",
+			effective_gid, real_gid,
+			getegid(), getgid(), getpid());
+#endif
 		exit(PERM_ERROR);
 	}
 	effective_gid = real_gid;
