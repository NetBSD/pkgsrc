$NetBSD: patch-Makefile.gnu,v 1.1 2023/09/03 13:00:43 vins Exp $

Portability fixes for pkgsc.

--- Makefile.gnu.orig	2021-06-02 10:12:42.000000000 +0000
+++ Makefile.gnu
@@ -3,28 +3,15 @@ LOCALBASE?=	/usr/
 PROG=		filter-dkimsign
 MAN=		filter-dkimsign.8
 BINDIR=		${LOCALBASE}/libexec/opensmtpd/
-MANDIR=		${LOCALBASE}/share/man/man8
+MANDIR=		${LOCALBASE}/man/man8
 
 SRCS+=		main.c mheader.c
 
 ifdef HAVE_ED25519
 CFLAGS+=	-DHAVE_ED25519
 endif
-ifdef LIBCRYPTOPC
-CRYPT_CFLAGS!=	pkg-config --cflags ${LIBCRYPTOPC}
-CRYPT_LDFLAGS_L!=pkg-config --libs-only-L ${LIBCRYPTOPC}
-CRYPT_LDFLAGS_libdir!=pkg-config --variable libdir ${LIBCRYPTOPC}
-CRYPT_LDFLAGS=	${CRYPT_LDFLAGS_L}
-CRYPT_LDFLAGS+=	-Wl,-rpath,${CRYPT_LDFLAGS_libdir}
-CRYPT_LDADD!=	pkg-config --libs-only-l ${LIBCRYPTOPC}
-else
-CRYPT_CFLAGS=
-CRYPT_LDFLAGS=
-CRYPT_LDADD=	-lcrypto
-endif
 
-CFLAGS+=	-I${LOCALBASE}/include
-CFLAGS+=	-Wall -I${.CURDIR}
+CFLAGS+=	-Wall
 CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
 CFLAGS+=	-Wmissing-declarations
 CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual
@@ -32,27 +19,10 @@ CFLAGS+=	-Wsign-compare
 CFLAGS+=	${CRYPT_CFLAGS}
 CFLAGS+=	-I${CURDIR} -I${CURDIR}/openbsd-compat/
 
-LDFLAGS+=	-L${LOCALBASE}/lib
-LDFLAGS+=	${CRYPT_LDFLAGS}
-LDADD+=		${CRYPT_LDADD} -lopensmtpd
-
 INSTALL?=	install
 
-NEED_REALLOCARRAY?=	1
-NEED_RECALLOCARRAY?=	1
-NEED_STRLCAT?=		1
-NEED_STRTONUM?=		1
-NEED_PLEDGE?=		1
-
 MANFORMAT?=		mangz
 
-BINOWN?=	root
-BINGRP?=	root
-BINPERM?=	755
-MANOWN?=	root
-MANGRP?=	root
-MANPERM?=	644
-
 ifeq (${MANFORMAT}, mangz)
 TARGET_MAN=		${MAN}.gz
 CLEANFILES+=		${TARGET_MAN}
@@ -62,6 +32,13 @@ else
 TARGET_MAN=		${MAN}
 endif
 
+ifeq (${NEED_EXPLICIT_BZERO}, 1)
+SRCS+=		${CURDIR}/openbsd-compat/explicit_bzero.c
+CFLAGS+=	-DNEED_EXPLICIT_BZERO=1
+
+explicit_bzero.o: ${CURDIR}/openbsd-compat/explicit_bzero.c
+	${CC} ${CFLAGS} -c -o explicit_bzero.o ${CURDIR}/openbsd-compat/explicit_bzero.c
+endif
 ifeq (${NEED_REALLOCARRAY}, 1)
 SRCS+=		${CURDIR}/openbsd-compat/reallocarray.c
 CFLAGS+=	-DNEED_REALLOCARRAY=1
@@ -115,5 +92,5 @@ clean:
 
 .PHONY: install
 install: ${PROG}
-	${INSTALL} -D -o ${BINOWN} -g ${BINGRP} -m ${BINPERM} ${PROG} ${DESTDIR}${BINDIR}/${PROG}
-	${INSTALL} -D -o ${MANOWN} -g ${MANGRP} -m ${MANPERM} ${TARGET_MAN} ${DESTDIR}${MANDIR}/${TARGET_MAN}
+	${BSD_INSTALL_PROGRAM} ${PROG} ${DESTDIR}${BINDIR}/${PROG}
+	${BSD_INSTALL_MAN} ${TARGET_MAN} ${DESTDIR}${MANDIR}/${TARGET_MAN}
