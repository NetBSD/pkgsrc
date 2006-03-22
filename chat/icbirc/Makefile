# $NetBSD: Makefile,v 1.10 2006/03/22 22:50:31 tv Exp $

DISTNAME=	icbirc-1.8
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	tv@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server

WRKSRC=		${WRKDIR}/${PKGBASE}
MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

CPPFLAGS.Interix+= -Dsocklen_t=int
LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin man/man8

do-build:
.for f in ${SRCS}
	cd ${WRKSRC} && ${COMPILE.c} ${f}
.endfor
	cd ${WRKSRC} && ${LINK.c} -o icbirc ${SRCS:.c=.o}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbirc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/icbirc.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
