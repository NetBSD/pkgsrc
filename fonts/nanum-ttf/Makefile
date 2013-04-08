# $NetBSD: Makefile,v 1.3 2013/04/08 01:42:40 rodent Exp $

DISTNAME=	NanumFont_TTF_ALL
PKGNAME=	nanum-ttf-3.0
CATEGORIES=	fonts
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://hangeul.naver.com/
COMMENT=	Korean fonts distributed by Naver
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
