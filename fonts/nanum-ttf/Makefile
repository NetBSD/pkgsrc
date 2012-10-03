# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:28 asau Exp $

DISTNAME=	NanumFont_TTF_ALL
PKGNAME=	nanum-ttf-3.0
CATEGORIES=	fonts
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://hangeul.naver.com/
COMMENT=	Korean fonts distributed by Naver
LICENSE=	open-font-license

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
