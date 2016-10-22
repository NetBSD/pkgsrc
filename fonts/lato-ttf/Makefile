# $NetBSD: Makefile,v 1.1 2016/10/22 08:01:43 wiz Exp $

DISTNAME=	Lato2OFL
PKGNAME=	lato-ttf-2.015
CATEGORIES=	fonts
MASTER_SITES=	http://www.latofonts.com/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.latofonts.com/lato-free-fonts/
COMMENT=	Free Sans Serif font Lato by Lukasz Dziedzic
LICENSE=	ofl-v1.1

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}/Lato2OFL
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	share/fonts/X11/TTF
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
