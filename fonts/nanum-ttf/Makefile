# $NetBSD: Makefile,v 1.4 2014/06/01 16:35:36 wiz Exp $

DISTNAME=	NanumFont_TTF_ALL
PKGNAME=	nanum-ttf-3.0
PKGREVISION=	1
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

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
