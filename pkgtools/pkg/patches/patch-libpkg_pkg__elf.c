$NetBSD: patch-libpkg_pkg__elf.c,v 1.3 2025/02/10 13:13:27 wiz Exp $

Avoid symbol conflicts on NetBSD due to libelf.h vs. exec_elf.h.

--- libpkg/pkg_elf.c.orig	2018-01-06 22:53:49.000000000 +0000
+++ libpkg/pkg_elf.c
@@ -48,7 +48,7 @@
 #include <fcntl.h>
 #include <gelf.h>
 #include <libgen.h>
-#if defined(HAVE_LINK_H) && !defined(__DragonFly__) && defined(HAVE_LIBELF)
+#if defined(HAVE_LINK_H) && !defined(__DragonFly__) && !defined(HAVE_LIBELF)
 #include <link.h>
 #endif
 #include <paths.h>
