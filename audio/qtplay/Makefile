# $NetBSD: Makefile,v 1.1.1.1 2007/05/13 12:18:48 schmonz Exp $
#

DISTNAME=	qtplay1.3.1
PKGNAME=	${DISTNAME:S/qtplay/qtplay-/}
CATEGORIES=	audio
MASTER_SITES=	http://rainbowflight.googlepages.com/#qtplay

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://rainbowflight.googlepages.com/
COMMENT=	QuickTime command-line player

ONLY_FOR_PLATFORM=	Darwin-*-*

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	rm -f ${WRKSRC}/qtplay

do-build:
	cd ${WRKSRC} && \
	cc -o qtplay -framework Carbon -framework QuickTime qtplay.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtplay ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qtplay.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
