# $NetBSD: Makefile,v 1.17 2012/10/03 00:02:37 asau Exp $

DISTNAME=	icbirc-1.8
PKGREVISION=	1
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
CFLAGS.SunOS+=		-DNEED_PROGNAME

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-build:
.for f in ${SRCS}
	cd ${WRKSRC} && ${COMPILE.c} ${f}
.endfor
	cd ${WRKSRC} && ${LINK.c} -o icbirc ${SRCS:.c=.o}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icbirc ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/icbirc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
