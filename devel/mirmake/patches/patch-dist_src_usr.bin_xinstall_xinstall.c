$NetBSD: patch-dist_src_usr.bin_xinstall_xinstall.c,v 1.1 2023/07/12 19:34:39 vins Exp $

NetBSD doesn't define `strtofflags'.

--- dist/src/usr.bin/xinstall/xinstall.c.orig	2014-12-20 22:27:39.000000000 +0000
+++ dist/src/usr.bin/xinstall/xinstall.c
@@ -134,7 +134,7 @@
 #endif
 	u_int iflags;
 	int ch, no_target;
-#if defined(BSD) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 	char *flags;
 #endif
 	char *to_name, *group = NULL, *owner = NULL;
@@ -155,7 +155,7 @@
 			/* For backwards compatibility. */
 			break;
 		case 'f':
-#if defined(BSD) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 			flags = optarg;
 			if (strtofflags(&flags, &fset, NULL))
 				errx(EX_USAGE, "%s: invalid flag", flags);
