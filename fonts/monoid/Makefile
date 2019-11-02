# $NetBSD: Makefile,v 1.3 2019/11/02 22:24:42 rillig Exp $

PKGNAME=	monoid-0.61
DISTNAME=	Monoid
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/larsenwork/monoid/2db2d289f4e61010dd3f44e09918d9bb32fb96fd/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://larsenwork.com/monoid/
COMMENT=	Programming font with monospaced ligatures
LICENSE=	ofl-v1.1 OR mit

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_LANGUAGES=		# none
WRKSRC=			${WRKDIR}
NO_BUILD=		yes
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
