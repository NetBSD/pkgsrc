# $NetBSD: Makefile,v 1.7 2005/03/10 13:22:00 tv Exp $

DISTNAME=	icbirc-1.8
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server
WRKSRC=		${WRKDIR}/${PKGBASE}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

CPPFLAGS.Interix+= -Dsocklen_t=int
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
