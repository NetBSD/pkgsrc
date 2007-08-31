# $NetBSD: Makefile,v 1.14 2007/08/31 10:37:36 drochner Exp $

DISTNAME=	mp3check-0.8.3
CATEGORIES=	audio
MASTER_SITES=	http://jo.ath.cx/soft/mp3check/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://jo.ath.cx/soft/mp3check/
COMMENT=	Check MP3 files for consistency

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

BUILD_TARGET=	mp3check

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
