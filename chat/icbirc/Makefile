# $NetBSD: Makefile,v 1.5 2004/06/26 22:17:36 adrianp Exp $

DISTNAME=	icbirc-1.7
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server

MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

LIBS.SunOS+=	-lsocket -lnsl

do-build:
	cd ${WRKSRC};							\
	for SRC in ${SRCS}; do						\
	  ${CC} $$SRC ${CFLAGS} -c;					\
	done;								\
	${CC} ${SRCS:S/.c/.o/} ${CFLAGS} ${LDFLAGS} -o icbirc ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbirc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icbirc.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
