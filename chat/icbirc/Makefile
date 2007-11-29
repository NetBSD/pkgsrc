# $NetBSD: Makefile,v 1.14 2007/11/29 13:04:04 sketch Exp $

DISTNAME=	icbirc-1.8
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/icbirc.html
COMMENT=	Proxy IRC client and ICB server

# uses strlcpy
NOT_FOR_PLATFORM=	Linux-*-*

WRKSRC=		${WRKDIR}/${PKGBASE}
MAKE_ENV+=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man"

SRCS=		icb.c irc.c icbirc.c

CPPFLAGS.Interix+=	-Dsocklen_t=int
LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-build:
.for f in ${SRCS}
	cd ${WRKSRC} && ${COMPILE.c} ${f}
.endfor
	cd ${WRKSRC} && ${LINK.c} -o icbirc ${SRCS:.c=.o}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbirc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/icbirc.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
