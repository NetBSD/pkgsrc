# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:11 rillig Exp $

DISTNAME=	NanumFont_TTF_ALL
PKGNAME=	nanum-ttf-3.0
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://hangeul.naver.com/
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
