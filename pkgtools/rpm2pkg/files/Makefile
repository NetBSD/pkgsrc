#	$NetBSD: Makefile,v 1.3 2011/01/19 16:23:02 tron Exp $

PROG=		rpm2pkg
SRCS=		fileio.c package-list.c parse-rpm.c rpm2pkg.c
SRCS+=		fileio-bzlib.c fileio-lzma.c fileio-plain.c fileio-zlib.c
MAN=

BINDIR=		${PREFIX}/sbin
LDADD=		-lbz2 -llzma -lz
WARNS=		4

#CFLAGS+=	-g
#LDFLAGS+=	-g

.PATH: ${FILESDIR}

.include <bsd.prog.mk>
