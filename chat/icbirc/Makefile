# $NetBSD: Makefile,v 1.6 2004/11/19 13:03:30 tv Exp $

DISTNAME=	icbirc-1.8
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server
WRKSRC=		${WRKDIR}/${PKGBASE}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

LDFLAGS.SunOS+=	-lsocket -lnsl

do-build:
.for f in ${SRCS}
	cd ${WRKSRC} && ${COMPILE.c} $f
.endfor
	cd ${WRKSRC} && ${LINK.c} -o icbirc ${SRCS:.c=.o}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbirc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/icbirc.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
