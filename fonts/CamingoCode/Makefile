# $NetBSD: Makefile,v 1.3 2019/06/24 10:59:40 nia Exp $

DISTNAME=	CamingoCode-v1.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	fonts
MASTER_SITES=	http://www.janfromm.de/_data/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.janfromm.de/typefaces/camingomono/camingocode/
COMMENT=	Font designed for source-code editors
LICENSE=	cc-by-nd-v3.0-license

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	share/fonts/X11/TTF share/doc/CamingoCode

do-build:

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	cd ${WRKSRC} && ${INSTALL_DATA} readme* ${DESTDIR}${PREFIX}/share/doc/CamingoCode

.include "../../mk/bsd.pkg.mk"
