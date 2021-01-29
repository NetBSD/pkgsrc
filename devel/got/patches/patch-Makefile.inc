$NetBSD: patch-Makefile.inc,v 1.1 2021/01/29 20:35:11 ryoon Exp $

--- Makefile.inc.orig	2020-12-19 00:55:45.000000000 +0000
+++ Makefile.inc
@@ -4,6 +4,19 @@ CPPFLAGS += -DGOT_LIBEXECDIR=${LIBEXECDI
 #CFLAGS += -DGOT_OBJ_CACHE_DEBUG
 #CFLAGS += -DGOT_DIFF_NO_MMAP
 
+# work around https://gcc.gnu.org/bugzilla/show_bug.cgi?id=63567
+#.include <bsd.compiler.mk>
+#.if ${COMPILER_TYPE} == "gcc" && ${COMPILER_VERSION} < 50000
+#CSTD = gnu89
+#.endif
+
+OPENBSD_COMPAT := ${.PARSEDIR}/openbsd-compat
+CFLAGS += ${CPPFLAGS} -I${OPENBSD_COMPAT}
+CFLAGS += -Wno-pointer-sign
+
+LDFLAGS += -L${OPENBSD_COMPAT}
+LDADD += -lopenbsd-compat #-lmd
+
 .if "${GOT_RELEASE}" == "Yes"
 PREFIX ?= /usr/local
 BINDIR ?= ${PREFIX}/bin
