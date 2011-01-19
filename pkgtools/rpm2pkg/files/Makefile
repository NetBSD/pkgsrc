#	$NetBSD: Makefile,v 1.2 2011/01/19 11:49:18 tron Exp $

PROG=		rpm2pkg
SRCS=		fileio.c package-list.c parse-rpm.c rpm2pkg.c
SRCS+=		fileio-bzlib.c fileio-lzma.c fileio-plain.c fileio-zlib.c
MAN=		rpm2pkg.8

BINDIR=		${PREFIX}/sbin
LDADD=		-lbz2 -llzma -lz
WARNS=		4

NEED_OWN_INSTALL_TARGET=	yes

#CFLAGS+=	-g
#LDFLAGS+=	-g

.PATH: ${FILESDIR}

.include <bsd.prog.mk>
