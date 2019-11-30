#	$NetBSD: Makefile,v 1.5 2019/11/30 23:31:30 rin Exp $

PROG=		rpm2pkg
SRCS=		fileio.c package-list.c parse-rpm.c rpm2pkg.c
SRCS+=		fileio-bzlib.c fileio-lzma.c fileio-plain.c fileio-zlib.c
SRCS+=		fileio-zstd.c
MAN=

BINDIR=		${PREFIX}/sbin
LDADD=		-lbz2 -llzma -lz
LDADD+=		-lzstd
#WARNS=		4

#CFLAGS+=	-g
#LDFLAGS+=	-g

.PATH: ${FILESDIR}

.include <bsd.prog.mk>
