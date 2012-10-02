# $NetBSD: Makefile,v 1.18 2012/10/02 23:47:58 asau Exp $

DISTNAME=	mp3check-0.8.3
CATEGORIES=	audio
MASTER_SITES=	http://jo.ath.cx/soft/mp3check/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jo.ath.cx/soft/mp3check/
COMMENT=	Check MP3 files for consistency
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

BUILD_TARGET=	mp3check

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
