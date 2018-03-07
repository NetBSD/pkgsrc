$NetBSD: patch-backup_libcd64_cd64io.c,v 1.1 2018/03/07 12:34:55 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- backup/libcd64/cd64io.c.orig	2017-07-29 05:55:48.000000000 +0000
+++ backup/libcd64/cd64io.c
@@ -827,14 +827,29 @@ int cd64_open_rawio(struct cd64_t *cd64)
 			return 0;
 		}
 	}
-#elif defined __OpenBSD__
-	/* I cannot test i386_set_ioperm(), so I only use i386_iopl() */
+#elif (defined __OpenBSD__ || defined __NetBSD__) && defined __i386__
 	ret = i386_iopl(3);
 	if (ret == -1) {
 		cd64->notice_callback2("i386_iopl: %s", strerror(errno));
 		return 0;
 	}
-#elif defined __FreeBSD__
+#endif
+#ifdef __x86_64__
+#ifdef __OpenBSD__
+	ret = amd64_iopl(3);
+	if (ret == -1) {
+		cd64->notice_callback2("amd64_iopl: %s", strerror(errno));
+		return 0;
+	}
+#elif defined __NetBSD__
+	ret = x86_64_iopl(3);
+	if (ret == -1) {
+		cd64->notice_callback2("x86_64_iopl: %s", strerror(errno));
+		return 0;
+	}
+#endif
+#endif
+#ifdef __FreeBSD__
 	cd64->portdevfd = open("/dev/io", O_RDWR);
 	if (cd64->portdevfd == -1) {
 		cd64->portdevfd = 0;
