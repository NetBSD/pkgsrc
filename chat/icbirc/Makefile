# $NetBSD: Makefile,v 1.4 2004/04/01 16:00:42 tv Exp $

DISTNAME=	icbirc-1.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server

MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
LIBS+=	-lsocket -lnsl
.endif

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
