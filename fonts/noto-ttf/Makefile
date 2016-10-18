# $NetBSD: Makefile,v 1.3 2016/10/18 12:40:25 wiz Exp $

DISTNAME=	Noto-hinted
PKGNAME=	noto-ttf-20160531
CATEGORIES=	fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.google.com/get/noto/
COMMENT=	Noto fonts for all languages
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
