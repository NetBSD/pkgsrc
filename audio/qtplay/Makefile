# $NetBSD: Makefile,v 1.5 2014/01/01 15:05:37 schmonz Exp $
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
	cc -o ${PKGBASE} -arch i386 -framework Carbon -framework QuickTime ${CFLAGS} ${CPPFLAGS} qtplay.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qtplay.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
