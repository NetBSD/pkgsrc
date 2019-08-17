# $NetBSD: Makefile,v 1.1 2019/08/17 09:47:47 ng0 Exp $

PKGNAME=	ibm-plex-ttf-2.0.0
GITHUB_PROJECT=	plex
DISTNAME=	TrueType
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=IBM/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/IBM/plex/
COMMENT=	IBM plex typeface (TrueType)
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTSDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*.ttf  ${DESTDIR}${FONTSDIR}


.include "../../mk/bsd.pkg.mk"
