# $NetBSD: Makefile,v 1.21 2021/10/17 18:14:04 tm Exp $

DISTNAME=	icbirc-2.1
CATEGORIES=	chat
MASTER_SITES=	http://www.benzedrine.ch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.benzedrine.ch/icbirc.html
COMMENT=	Proxy IRC client and ICB server
LICENSE=	2-clause-bsd

# uses strlcpy
BROKEN_ON_PLATFORM=	Linux-*-*

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
