# $NetBSD: Makefile,v 1.1 2015/07/02 13:20:31 wiz Exp $

DISTNAME=	noto-ttf-20150630
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlei18n/}
GITHUB_PROJECT=	noto-fonts
GITHUB_TAG=	v2015-06-30

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.google.com/get/noto/
COMMENT=	Noto fonts for all languages
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_X11BASE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/noto-fonts-2015-06-30

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/alpha/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/unhinted/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
