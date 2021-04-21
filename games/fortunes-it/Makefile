# $NetBSD: Makefile,v 1.3 2021/04/21 15:38:52 wiz Exp $

DISTNAME=	fortune-it-1.99
PKGNAME=	${DISTNAME:S/fortune/fortunes/}
CATEGORIES=	games
MASTER_SITES=	http://www.fortune-it.net/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://www.fortune-it.net/
COMMENT=	Italian fortunes
LICENSE=	public-domain

BUILD_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=	${LOCALBASE}/bin/strfile

do-build:
	find ${WRKSRC}/testi/ -type f ! -name "*.dat" -exec ${STRFILE} {} \;

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fortune/it
	${INSTALL_DATA} ${WRKSRC}/testi/* \
		${DESTDIR}${PREFIX}/share/games/fortune/it

.include "../../mk/bsd.pkg.mk"
